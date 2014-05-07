
/*
TIS IS AN OBJECT POOLED CLASS, THEREFORE THE CONSTRUCTOR MUST NOT HAVE ANI VARIABLES
IT WILL BE SET UNSING THE void initClient() and unset with resetClient()
*/

#include "Client.h"
#include "Server.h"

Client::Client() : readCircularBuffer(BUF_SIZE)
{
}

CircularBuffer<char>                &Client::getReadCircularBuffer()
{
    return this->readCircularBuffer;
}

void Client::initClient(Socket* s, Server *serv)
{
    this->isBody_ = false;
    this->isPersistent_ = false;
    this->socket_ = s;
    getTime(&(this->begin_));
    this->end_ = TIME_END;
    this->getEnd();
    this->_serv = serv;
    this->stat_ = new ABSSTAT();

    // API handle
    this->_serv->getModuleManager().fillModsCallback(this->_serv->getConf(), this->modsCallback_, this->socket_);
    this->message_ = new HttpMessage(this->socket_);
    this->input_ = this->message_->newDataStream();
    this->output_ = this->message_->newDataStream();

    /*
   *  API STEP IN
   */
    if (this->checkIfModAtStep(zia::api::STEP_IN) == true)
        this->execMethodAtStep(zia::api::STEP_IN, this->input_);
}

void Client::resetClient()
{
    while (this->wstrings_.empty() == false)
    {
        if (this->wstrings_.back().first > 0)
            CLOSE(this->wstrings_.back().first);
        this->wstrings_.pop_back();
    }
    this->readCircularBuffer.reset();
    delete this->stat_;
    delete this->input_;
    delete this->output_;
    delete this->message_;
    delete socket_;
}

Client::~Client()
{
}

bool		Client::checkIfModAtStep(zia::api::HttpStepID sId)
{
    std::list< zia::api::HttpStep::Pair >::iterator iT = this->modsCallback_.begin();

    for (; iT != this->modsCallback_.end(); ++iT)
    {
        if (iT->mStep == sId)
            return (true);
    }
    return (false);
}

zia::api::AStream*		Client::execMethodAtStep(zia::api::HttpStepID sId, zia::api::AStream* input)
{
    std::list< zia::api::HttpStep::Pair >::iterator iT = this->modsCallback_.begin();

    for (; iT != this->modsCallback_.end(); ++iT)
    {
        if (iT->mStep == sId)
            return (iT->mCallback(*(this->message_), input));
    }
    return (NULL);
}

Socket*		Client::getSocket() const
{
    return this->socket_;
}

Server*		Client::getServer()
{
    return (this->_serv);
}

int				Client::readData() // BUFFER CIRCULAIRE read :)
{
    memset(this->rbuf_, 0, BUF_SIZE + 1);
    int len = this->socket_->recvSocket(this->rbuf_, BUF_SIZE);
    if (len <= 0)
        return -1;
    //std::cout << this->rbuf_ << std::endl; /* BUFFER DE READ */
    this->readCircularBuffer.write(this->rbuf_, static_cast<unsigned int>(len));
    return len;
}

int				Client::writeData()
{
    if (this->wstrings_.empty())
        return 0;
    // tmp
    //  return -1;

    unsigned int		inbuf = 0;
    memset(this->wbuf_, 0, BUF_SIZE + 1);

    if (this->wstrings_.back().first > 0 && this->wstrings_.back().second.empty()) // is a file descriptor
    {
        fd_set			readfd;
        unsigned int	fd = this->wstrings_.back().first;
        timeval			tv;

        tv.tv_sec = 0;
        tv.tv_usec = 0;
        FD_ZERO(&readfd);
        FD_SET(fd, &readfd);
        select(fd + 1, &readfd, NULL, NULL, &tv);
        if (FD_ISSET(fd, &readfd))
        {
            int r = READ(fd, this->wbuf_, BUF_SIZE);
            // zip
            if (r > 0)
                inbuf = r;
            else if (r <= 0)
            {
                CLOSE(fd);
                this->wstrings_.pop_back();
            }
        }
    }
    else if (this->wstrings_.back().second.empty() == false && this->wstrings_.back().first == 0) // is a string
    {
        if (this->wstrings_.back().second.length() > BUF_SIZE)
	{
            inbuf = BUF_SIZE;
            memcpy(this->wbuf_, this->wstrings_.back().second.c_str(), inbuf);
            this->wstrings_.back().second.erase(0, BUF_SIZE);
	}
        else
	{
            inbuf = this->wstrings_.back().second.length();
            memcpy(this->wbuf_, this->wstrings_.back().second.c_str(), inbuf);
            this->wstrings_.pop_back();
        }
    }
    else // is nothing
    {
        this->wstrings_.pop_back();
        return -1;
    }

    int					ret = 0;
    if (inbuf > 0)
    {
        // STEP_OUT
        //std::cout << this->wbuf_; // BUFFER WRITE
        ret = this->socket_->sendSocket(this->wbuf_, inbuf);
    }
    return ret;
}

bool				Client::isRData()
{
    int ret = this->readCircularBuffer.findFromArray(EOL, EOL_SIZE);
    if (ret < 0)
        return false;
    return true;
}

bool				Client::isWData()
{
    return !this->wstrings_.empty();
}



std::string			Client::getHeader() // BUFFER CIRCULAIRE renvoyer le header (du debut -> \r\n\r\n non compris)
{
    int				found;
    std::string		buffer = "";
    char			*ans = 0;

    found = this->readCircularBuffer.findFromArray(EOL, EOL_SIZE);
    if (found > 0)
    {   ans = new char [found + EOL_SIZE + 1];
        found = this->readCircularBuffer.read(ans , found + EOL_SIZE);
        ans[found - EOL_SIZE] = 0;
        buffer = ans;
        delete [] ans;
    }
    return buffer;
}
std::string			Client::getBody() // BUFFER CIRCULAIRE renvoyer le header (du debut -> \r\n\r\n non compris)
{
    std::string		buffer = "";
    char                *ans = 0;

    unsigned int size = atoi(this->getMessage()->http()["http"]["Content-Length"].mValue.c_str());
    std::cout << std::endl << size << std::endl << std::endl;
    if (size > this->readCircularBuffer.getSize())
        size = this->readCircularBuffer.getSize();
    ans = new char [size + 1];
    this->readCircularBuffer.read(ans , size);
    ans[size] = 0;
    buffer = ans;
    delete [] ans;
    
    return buffer;
}


std::string	Client::getData() // BUFFER CIRULAIRE pareil que getHeader mais \r\n\r\n compris
{
    int			found;
    std::string		buffer = "";
    char                *ans;

    found = this->readCircularBuffer.findFromArray(EOL, EOL_SIZE);
    if (found > 0)
    {   ans = new char [found + EOL_SIZE + 1];
        found = this->readCircularBuffer.read(ans , found + EOL_SIZE);
        ans[found] = 0;
        buffer = ans;
        delete [] ans;
    }
    return buffer;
}

void				Client::setData(const std::string& s)
{
    std::pair<unsigned int, std::string> p(0, s);
    this->wstrings_.push_front(p);
}

void				Client::setData(unsigned int fd)
{
    std::pair<unsigned int, std::string> p(fd, "");
    this->wstrings_.push_front(p);
}


const timeval&		Client::getBegin() const
{
    return this->begin_;
}

const timeval&		Client::getEnd()
{
    //getTime(this->begin);
    //this->tvend_ = this->begin_;
    getTime(&(this->tvend_), this->end_, true);
    return this->tvend_;
}

bool				Client::isEnd()
{
    timeval now;
    getTime(&now);

    double begin = now.tv_sec + (now.tv_usec * 1e-6);
    double end = this->tvend_.tv_sec + (this->tvend_.tv_usec * 1e-6);
    if (begin >= end)
        return true;
    return false;
}

int					Client::getTimeout(int old)
{
    timeval now;
    getTime(&now);
    double dCur = (this->tvend_.tv_sec + (this->tvend_.tv_usec * 1e-6))
                  - (now.tv_sec + (now.tv_usec * 1e-6));
    if (dCur <= 0)
        return 0;

    int cur = static_cast<int>(dCur * 1000.);

    if ((old >= 0 && cur < old) || old < 0)
    {
        old = cur;
    }
    return old;
}

void				Client::setEnd(unsigned int pause)
{
    this->end_ = pause;
    this->getEnd();
}

void				Client::resetEnd()
{
    this->setEnd(TIME_END);
}

bool				Client::isPersistent() const
{
    return this->isPersistent_;
}

void				Client::isPersistent(bool b)
{
    this->isPersistent_ = b;
}

zia::api::IMessage*		Client::getMessage() const
{
    return (this->message_);
}

zia::api::AStream*		Client::getInput() const
{
    return (this->input_);
}

zia::api::AStream*		Client::getOutput() const
{
    return (this->output_);
}

IStat*					Client::getStat() const
{
    return this->stat_;
}
