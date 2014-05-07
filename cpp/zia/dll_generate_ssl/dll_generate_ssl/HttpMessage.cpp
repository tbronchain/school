#include "HttpMessage.h"

HttpMessage::HttpMessage(zia::api::IConnection *connection)
  : IMessage(*connection)
{
  
}

HttpMessage::HttpMessage(const HttpMessage &amessage)
	: IMessage(amessage)
{

}

HttpMessage::~HttpMessage()
{
	
}

HttpMessage& 			HttpMessage::operator=(const HttpMessage &amessage)
{
	if (&amessage != this)
	{
		this->mConnection = amessage.mConnection;
		this->mLog = amessage.mLog;
		this->mHttp = amessage.mHttp;
		this->mHttpResp = amessage.mHttpResp;
	}
	return (*this);
}

void					HttpMessage::forceDeleteStream(zia::api::AStream *stream)
{
	delete stream;
}

zia::api::AStream*		HttpMessage::newDataStream()
{
	return (new Stream());
}

std::string				HttpMessage::httpRespString()
{
	std::string			resp = "";

	if (this->mHttpResp->has("version") ||  this->mHttpResp->has("code") || this->mHttpResp->has("reason") || this->mHttpResp->has("http"))
		; //throw
	resp += this->mHttpResp->get("version").mValue + " " + this->mHttpResp->get("code").mValue + this->mHttpResp->get("reason").mValue + "\r\n";

	std::map<std::string, zia::api::DataTree >::const_iterator	it = this->mHttpResp->get("http").mSubs.begin();
	std::map<std::string, zia::api::DataTree >::const_iterator	itEnd = this->mHttpResp->get("http").mSubs.end();

	while (it != itEnd)
	{
	        	resp += it->first + ": ";
		if (it->second.mValue != "")
			resp += it->second.mValue;
		else
		{
			std::map<std::string, zia::api::DataTree >::const_iterator	itval = it->second.mSubs.begin();
			std::map<std::string, zia::api::DataTree >::const_iterator	itvalEnd = it->second.mSubs.end();

			for (;itval != itvalEnd; ++itval)
				resp += itval->first + " ";
		}
		++it;
		if (it != itEnd)
			resp += "\r\n";
	}
	return resp;
}

zia::api::IMessage*		HttpMessage::newMessageAtStep (zia::api::HttpStepID stepId, zia::api::AStream &input)
{
	if (5 == 5)
	 ;// methode à changer
	return (this);
}

zia::api::AStream * 	HttpMessage::newResourceStream (zia::api::Resource resource, zia::api::ResourceType type, zia::api::FdCallback readingCallback, zia::api::FdCallback writingCallback)
{
	if (5 == 5)
		;// method à changer
	return (new Stream);
}
