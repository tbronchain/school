#include "Stream.h"

Stream::Stream()
{
	this->mClosed = false;
}

Stream::~Stream()
{

}

int			Stream::callReader()
{
	return (this->mReader(*this));
}

bool		Stream::canRead() const
{
	if (this->mStream.str().size() == 0)
		return (false);
	return (true);
}

void		Stream::write(const std::string& str)
{
	this->mStream << str;
}

void		Stream::write(const char* buff, size_t buffSize)
{
	this->mStream.write(buff, buffSize);
}

size_t		Stream::read(char* buff, size_t maxBuffSize)
{
	this->mStream.read(buff, maxBuffSize);
	return (0);
}

void		Stream::drop()
{
	this->mStream.str(std::string());
}

void		Stream::dropAll()
{
	this->mStream.str(std::string());
	this->mReader.clear();
}

void		Stream::flush()
{
	this->callReader();
}

void		Stream::close()
{
	while (this->canRead())
		this->callReader();
	this->mClosed = true;
}

void		Stream::forceClose()
{
	this->drop();
	this->mClosed = true;
}