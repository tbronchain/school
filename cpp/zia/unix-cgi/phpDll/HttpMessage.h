#ifndef HTTPMESSAGE_H
# define HTTPMESSAGE_H

#include "IMessage.hpp"
#include "IConnection.hpp"
#include "Stream.h"

class HttpMessage : public zia::api::IMessage
{
public:
							HttpMessage(zia::api::IConnection *connection);
							HttpMessage(const HttpMessage &);
	virtual					~HttpMessage();
	HttpMessage& 			operator=(const HttpMessage &);
	void					forceDeleteStream(zia::api::AStream *stream);
	zia::api::AStream*	 	newDataStream();
	zia::api::IMessage* 	newMessageAtStep (zia::api::HttpStepID stepId, zia::api::AStream &input);
	zia::api::AStream* 		newResourceStream (zia::api::Resource resource, zia::api::ResourceType type=zia::api::RCE_SOCKET, zia::api::FdCallback readingCallback=zia::api::FdCallback(), zia::api::FdCallback writingCallback=zia::api::FdCallback());
	std::string				httpRespString();
protected:
private:
};


#endif // !HTTPMESSAGE_H
