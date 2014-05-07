#include "AStream.hpp"

void		zia::api::AStream::setReader(Reader streamReader)
{
	this->mReader = streamReader;
}

void		zia::api::AStream::setCloseReader(Reader streamCloseReader)
{
	this->mCloseReader = streamCloseReader;
}

bool		zia::api::AStream::isReaderSet() const
{
	if (this->mReader.isSet() == true)
		return (true);
	return (false);
}

bool		zia::api::AStream::isCloseReaderSet() const
{
	if (this->mCloseReader.isSet() == true)
		return (true);
	return (false);
}

void		zia::api::AStream::setExpectedReadSize(size_t readingSize)
{
	this->mExpectedSize = readingSize;
}

bool		zia::api::AStream::isClosed() const
{
	return (this->mClosed);
}