#ifndef _ZIA_API_ISTREAM_H_
#define _ZIA_API_ISTREAM_H_

#include <string>

#include "defines.hpp"
#include "Callback.hpp"

_BOF_ZIA_API_

/*!
 * \brief Stream interface class.
 *
 * Base of your Zia, this class will permit you to manage all
 * asynchronous datas in your Zia.
 * With this sytem, you will be capable to implement any management
 * system behind the interface.
 *
 * You can write directly into it, and, with the AStream::Reader callback,
 * you are called when there is something to read in it.
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// Non-virtual AStream members to implement:
//
AStream::AStream();
AStream::~AStream();
void            AStream::setReader(Reader streamReader);
void            AStream::setCloseReader(Reader streamCloseReader);
bool            AStream::isReaderSet() const;
bool            AStream::isCloseReaderSet() const;
void            AStream::setExpectedReadSize(size_t readingSize);
bool            AStream::isClosed() const;

//
// Minimal AStream inherits implementation:
//
namespace zia {

class X : public api::AStream
{
public:
    X();
    virtual ~X();

    virtual int         callReader();
    virtual bool        canRead() const;
    virtual void        write(const std::string& str);
    virtual void        write(const char* buff, size_t buffSize);
    virtual size_t      read(char* buff, size_t maxBuffSize);
    virtual void        drop();
    virtual void        dropAll();
    virtual void        flush();
    virtual void        close();
    virtual void        forceClose();

};

}

 * \endcode
 *
 */
class AStream
{
public:

    /*!
     * \brief The AStream::Reader type.
     *
     * AStream::Reader is the type of AStream reading callback.
     * Callback on a method:
     * \code
     * int          ( AStream& )
     * \endcode
     */
    typedef zia::api::Callback< int (AStream&) >  Reader;

    /*!
     * \brief Constructor.
     *
     */
	AStream() {}

    /*!
     * \brief Destructor.
     */
	virtual ~AStream() {}

    /*!
     * \brief Set the AStream::Reader reader of the AStream for reading.
     *
     * \a streamReader will be called every time stream's datas will be
     * available for reading.
     *
     * To unset the reader, call without arguments.
     *
     * \param streamReader The AStream::Reader reader callback.
     */
    void                    setReader(Reader streamReader = Reader());

    /*!
     * \brief Set the close reader.
     *
     * The \a streamCloseReader will be called when closing the stream.
     * To unset the close reader, call without arguments.
     *
     * Note: After the \a streamCloseReader callback call, you should close
     * all your next AStream.
     *
     * \param streamCloseReader The AStream::Reader called one time
     * when the AStream will be closed.
     */
    void                    setCloseReader(Reader streamCloseReader = Reader());

    /*!
     * \brief Check if the AStream::Reader reader is set.
     *
     * \return true if the AStream::Reader reader is set.
     */
    bool                    isReaderSet() const;

    /*!
     * \brief Check if the AStream::Reader close callback is set.
     *
     * \return true if the AStream::Reader close callback is set.
     */
    bool                    isCloseReaderSet() const;

    /*!
     * \brief Set the excpeted reading size
     *
     * \param readingSize The expected size of data you want to
     * read when the reader is called.
     */
    void                    setExpectedReadSize(size_t readingSize);

    /*!
     * \brief Check if IStrean is closed.
     *
     * \return true if the AStream is closed.
     */
    bool                    isClosed() const;

    /*!
     * \brief Call the reader.
     *
     * \return the returned value of the callback.
     */
    virtual int             callReader() = 0;

    /*!
     * \brief Check if there is something to read.
     *
     * \return true if there is something to read.
     */
    virtual bool            canRead() const = 0;

    /*!
     * \brief Write a string in the AStream.
     *
     * The string will be copied in the AStream.
     *
     * \param str The string to write.
     */
    virtual void            write(const std::string& str) = 0;

    /*!
     * \brief Write raw data in the AStream.
     *
     * The datas will be copied in the AStream.
     *
     * \param buff The raw datas
     * \param buffSize The size in octets of the \a buff
     */
    virtual void            write(const char* buff, size_t buffSize) = 0;

    /*!
     * \brief Read data from the AStream.
     *
     * This copy data in \a buff, then remove it from the AStream.
     *
     * The reader will be called while there is enought data to read,
     * so you should read or setExpectedReadSize inside your reader callback.
     *
     * \param buff Where the reading data will be copied.
     * \param maxBuffSize The maxium size in octets to read and copy in \a buff.
     * \return The number of octets read.
     */
    virtual size_t          read(char* buff, size_t maxBuffSize) = 0;

    /*!
     * \brief Drop datas.
     *
     * Remove datas from the AStream without calling the reader.
     */
    virtual void            drop() = 0;

    /*!
     * \brief Drop datas everytime.
     *
     * Drop datas everytime and unset the reader.
     * Re-set the reader to stop drop all.
     */
    virtual void            dropAll() = 0;

    /*!
     * \brief Flush datas.
     *
     * Call the reader whatever the expected size.
     */
    virtual void            flush() = 0;

    /*!
     * \brief Close the AStream.
     *
     * This will call the reader while there are datas.
     * If your reader dont read it, it may cause infinite loop
     */
    virtual void            close() = 0;

    /*!
     * \brief Close the AStream NOW.
     *
     * This will close the stream without send waiting datas.
     */
    virtual void            forceClose() = 0;

protected:
    /*!
     * \brief true if is closed.
     */
    bool                    mClosed;

    /*!
     * \brief Exepected reading size.
     */
    size_t                  mExpectedSize;

    /*!
     * \brief Reader callback
     */
    Reader                  mReader;

    /*!
     * \brief Reader callback on close
     */
    Reader                  mCloseReader;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_ISTREAM_H_ */