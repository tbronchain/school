#include <openssl/err.h>
#include <openssl/ssl.h>

#include "IConnection.hpp"
#include "init.hpp"

using namespace zia;

SSL_CTX*				ctx = 0;

#define PASSWORD "password"

int password_callback(char* buffer, int num, int rwflag, void* userdata) {
    if (num < (strlen(PASSWORD) + 1)) {
  return(0);
    }
    strcpy(buffer, PASSWORD);
    return strlen(PASSWORD);
}

class SslCertifSingle
{
public:

    static SslCertifSingle&       i()
    {
        if (mI == 0)
            mI = new SslCertifSingle();
        return (*mI);
    }

    static void                 end()
    {
        // dechargement du chiffrement
        if (mI == 0)
            delete mI;
        mI = 0;
    }

private:
    static SslCertifSingle*		mI;

    SslCertifSingle()
    {
		DH	*ret = 0;
		BIO *bio;

		// initialize SSL library by registering algorithms 
		SSL_library_init();

		// load and free error strings
		SSL_load_error_strings();

		// create a new SSL_CTX object as framework for TLS/SSL enabled functions
		ctx = SSL_CTX_new(SSLv23_server_method());

		// loads a certificate chain from file into ctx
		if(!(SSL_CTX_use_certificate_chain_file(ctx,
			"server.pem")))
			std::cerr << "Error : SSL_CTX_use_certificate_chain_file" << std::endl;

		/* au cas ou on crypte la private key? si pas fait le mdp est demander sur lentree standard*/

		SSL_CTX_set_default_passwd_cb(ctx,
		password_callback);

		// adds the first private key found in file to ctx 
		if(!(SSL_CTX_use_PrivateKey_file(ctx,
			"server.pem", SSL_FILETYPE_PEM)))
			std::cerr << "Error : SSL_CTX_use_PrivateKey_file" << std::endl;

		// specifies the locations for ctx, at which CA certificates for verification purposes are located
		if(!(SSL_CTX_load_verify_locations(ctx,
			"root.pem", 0)))
			std::cerr << "Error : SSL_CTX_load_verify_locations" << std::endl;

		// creates a new file BIO with mode mode the meaning of mode is the same as the stdio function fopen()
		if ((bio = BIO_new_file("dh1024.pem","r")) == NULL)
			std::cerr << "Error : BIO_new_file " << std::endl;

		ret = PEM_read_bio_DHparams(bio, NULL, NULL, NULL);

		BIO_free(bio);

		// sets DH parameters to be used to be dh
		if(SSL_CTX_set_tmp_dh(ctx, ret)<0)
			std::cerr << "Error : SSL_CTX_set_tmp_dh" << std::endl;
    }

    ~SslCertifSingle()
    {
        end();
    }

};

SslCertifSingle*		SslCertifSingle::mI = 0;

//////////////

class					SocketSSL : public api::IModule
{
public:
	static SocketSSL*     init(zia::api::IConnection& connection,
                             zia::api::IConf& conf)
    {
        return (new SocketSSL());
    }

	void        module_delete(api::IConnection&)
    {
        delete this;
    }

	api::AStream		*acceptSSL(api::IMessage& msg, api::AStream* input)
	{
		int r = 0;
		BIO *sbio;

		// returns a socket BIO using sock and close_flag
		std::cerr << atoi(msg.connection().info()["connection"]["socket"].mValue.c_str()) << std::endl;
		sbio = BIO_new_socket(atoi(msg.connection().info()["connection"]["socket"].mValue.c_str()), BIO_NOCLOSE);

		// creates a new SSL structure which is needed to hold the data for a TLS/SSL connection
		this->ssl_ = SSL_new(ctx);

		// connects the BIOs rbio and wbio for the read and write operations of the TLS/SSL (encrypted) side of ssl
		SSL_set_bio(this->ssl_, sbio, sbio);

		// waits for a TLS/SSL client to initiate the TLS/SSL handshake
		r = SSL_accept(this->ssl_);
		if (r != 1)
		{
			printf("SSL_accept() returned %d\n", r);
			printf("Error in SSL_accept(): %d\n", SSL_get_error(this->ssl_, r));
			char error[65535];
			ERR_error_string_n(ERR_get_error(), error, 65535);
			printf("Error: %s\n\n", error);
			std::cerr << "SSL_accept() failed" << std::endl;
			//msg.log() << zia::api::LOG_ERR << " SSL_accept() failed" << std::endl;
			//msg.log().flush();
		}

		// returns the result of the verification of the X509 certificate presented by the peer, if any
		if (SSL_get_verify_result(this->ssl_) != X509_V_OK)
		{
			std::cerr << "Certificate failed verification" << std::endl;
			//msg.log() << zia::api::LOG_ERR << " Certificate failed verification" << std::endl;
			//msg.log().flush();
		}

		return (input);
	}

	ssize_t		readSSL(api::Resource fd, void *data, size_t len)
	{
		ssize_t	r;

		r = BIO_read(this->io_, data, len);
		return (r);
	}

	ssize_t		writeSSL(api::Resource fd, void* data, size_t len)
	{
		ssize_t	r;

		r = BIO_puts(this->io_, static_cast<char*>(data));

		BIO_flush(this->io_);
		return (r);
	}

				~SocketSSL();
private:
	SSL			*ssl_;
	BIO			*ssl_bio_;
	BIO			*io_;
};

SocketSSL::~SocketSSL()
{
	//BIO_free(this->io_);
	//SSL_shutdown(this->ssl_);
}

extern "C"
{

    ZIA_INIT_EXPORT void                dll_load(zia::api::IConf& conf,
                                 zia::api::ILog& log)
    {
        SslCertifSingle::i();
    }

     ZIA_INIT_EXPORT zia::api::IModule*  module_new(std::list<zia::api::HttpStep::Pair>& steps,
                                   zia::api::IConnection& connection,
                                   zia::api::IConf& conf)
    {
        SocketSSL*        socket;

        if ((socket = SocketSSL::init(connection, conf)) == 0)
            return (0);

        // Set override of read and write for this connection.
        connection.setFdReadCallback(api::FdCallback::create<SocketSSL, &SocketSSL::readSSL>(socket));
        connection.setFdWriteCallback(api::FdCallback::create<SocketSSL, &SocketSSL::writeSSL>(socket));

        steps.push_back(api::HttpStep::Pair(
                            api::STEP_IN,
                            api::HttpStep::Callback::create<SocketSSL, &SocketSSL::acceptSSL>(socket)
                        ));
        return (socket);
    }

    ZIA_INIT_EXPORT void                dll_unload(zia::api::ILog& log)
    {
        SslCertifSingle::end();
    }

}


/*#include "init.hpp"

using namespace zia;

//
// Mon super HelloWorld module:
//
class HelloWorld : public api::IModule
{
public:
    HelloWorld() { }
    virtual ~HelloWorld() { }

    void        module_delete(api::IConnection&)
    {
        delete this;
    }

    //
    // Ma methode pour le HttpStep::Callback sur l'etape `EXEC`
    //
    api::AStream*       stepExec(api::IMessage& message, api::AStream* input)
    {

        // je cre un stream de sortie et je le garde dans `mOut`
        mOut = message.newDataStream();

        // je set le reader du stream pour le traitement des donnees
        input->setReader(
            api::AStream::Reader::create<HelloWorld, &HelloWorld::readerExec>(this)
        );

        // set le closeReader pour propager le close
        input->setCloseReader(
            api::AStream::Reader::create<HelloWorld, &HelloWorld::close>(this)
        );

        // je retourne le stream de sortie
        return (mOut);
    }

    //
    // Mon reader pour `EXEC`
    //
    int                 readerExec(api::AStream& input)
    {

        // ecrir "Hello World"
        mOut->write("<p> Hello World !! </p>");

        // Comme j'ai finis, je drop tout le reste des donnees de la requete
        input.dropAll();

        return (api::ZIA_OK);
    }

    //
    // Mon closeReader pour propager correctement le close
    //
    int                 close(api::AStream&)
    {
        mOut->close();
        return (api::ZIA_OK);
    }

private:
    api::AStream*       mOut;

};

extern "C"
{

    ZIA_INIT_EXPORT zia::api::IModule*  module_new(std::list<zia::api::HttpStep::Pair>& stepsCallbacks,
                                   zia::api::IConnection& connection,
                                   zia::api::IConf& conf)
    {
        HelloWorld*      hello = new HelloWorld();

        // je remplis la liste de HttpStep::Pair
        stepsCallbacks.push_back(
            api::HttpStep::Pair(api::STEP_EXEC,
                                api::HttpStep::Callback::create<HelloWorld, &HelloWorld::stepExec>(hello)
            )
        );
        // cad: je veux que `HelloWorld::stepExec` soit appeler a l'etape `EXEC`

        // je retourne mon IModule
        return (hello);
    }

}
*/