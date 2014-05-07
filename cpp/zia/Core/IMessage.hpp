#ifndef _ZIA_API_IMESSAGE_H_
#define _ZIA_API_IMESSAGE_H_

#include <string>

#include "defines.hpp"
#include "IConnection.hpp"
#include "AStream.hpp"
#include "HttpStep.hpp"
#include "DataTree.hpp"
#include "ILog.hpp"
#include "Log.h"

_BOF_ZIA_API_

/*!
 * \brief Resource types.
 *
 * See newResourceStream.
 */
enum ResourceType
{
    RCE_SOCKET,
    RCE_FILE,
    RCE_PIPE
};

/*!
 * \brief Manage entierly the current Message.
 *
 * Represente a http message entierly (request or response).
 * IMessage permits you to store all informations about this message,
 * and manipulate the execution flow ot it.
 *
 * \a http datas represents the datas in the http header.
 * \a info datas represents all others message informations.
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// Non-virtual IMessage members to implement:
//
IMessage::IMessage(api::IConnection& connection);
IMessage::~IMessage();
bool                    IMessage::isParsed() const;
api::DataTree&          IMessage::http();
api::DataTree&          IMessage::httpResp();
api::IConnection&       IMessage::connection();
api::ILog&              IMessage::log();

//
// Minimal IMessage inherits implementation:
//
namespace zia {

class X : public api::IMessage
{
public:
    X(api::IConnection& connection) ;
    virtual ~X();

    virtual api::AStream*       newDataStream();
    virtual api::AStream*       newResourceStream(
                                    api::Resource resource,
                                    api::FdCallback readingCallback = api::FdCallback(),
                                    api::FdCallback writingCallback = api::FdCallback()
                                );
    virtual void                forceDeleteStream(api::AStream* stream);
    virtual api::IMessage*      newMessageAtStep(api::HttpStep::ID stepId, api::AStream& input);

};

}

 * \endcode
 */
class IMessage
{
public:
    /*!
     * \brief Constructor.
     *
     */
    IMessage(api::IConnection& connection)
      : mConnection(connection)/*, mLog(new Log)*/, mHttp(new DataTree), mHttpResp(new DataTree)
	{

	}

    virtual ~IMessage()
	{
	  //delete mLog;
		delete mHttp;
		delete mHttpResp;
	}

    IMessage(const IMessage& amessage)
		: mConnection(amessage.mConnection), mLog(amessage.mLog), mHttp(amessage.mHttp), mHttpResp(amessage.mHttpResp)
	{

	}
    IMessage&                   operator = (const IMessage& amessage)
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

    /*!
     * \brief Check if the http header is parsed.
     *
     * \return true if the http header datas are ready for reading,
     * false if the http header is not yet totaly parsed.
     */
    bool                        isParsed() const
	{
		return this->mParsed;
	}

    /*!
     * \brief Get request http header datas.
     */
    api::DataTree&              http()
	{
		return *(this->mHttp);
	}

    /*!
     * \brief Get response http header datas.
     *
     */
    ::zia::api::DataTree&              httpResp()
	{
		return *(this->mHttpResp);
	}
    /*!
     * \brief Get the IConnection.
     */
    api::IConnection&           connection()
	{
		return this->mConnection;
	}

    /*!
     * \brief Get the ILog.
     *
     * Log about message.
     */
    api::ILog&                  log()
	{
		return *(this->mLog);
	}


    /*!
     * \brief Create a data AStream.
     *
     * Data AStream means that you can write on it, and when
     * the stream aquire enought data, it call its Reader.
     *
     * \return A new AStream.
     */
    virtual api::AStream*       newDataStream() = 0;

    /*!
     * \brief Create a AStream which handle a system resource.
     *
     * Under unix/linux, \a FD will be a file descriptor.
     * Under Windows, \a FD will be an HANDLE (which is, int fact,  an \c int too).
     *
     * \param resource The ressource to be handle by the AStream.
     * \param type The type of the \a resource.
     * \param readingCallback If set, this will be used to read from the \a FD.
     * \param writingCallback If set, this will be used to write on the \a FD.
     * \return The AStream wrapping the \a FD/HANDLE.
     */
    virtual api::AStream*       newResourceStream(api::Resource resource,
                                                  api::ResourceType type = api::RCE_SOCKET,
                                                  api::FdCallback readingCallback = api::FdCallback(),
                                                  api::FdCallback writingCallback = api::FdCallback()) = 0;

    /*!
     * \brief Force deletion of a AStream.
     *
     * Warning: the \a stream must not be used by something.
     * PS: Normal way to delete a stream is to close it.
     *
     * \param stream The AStream to delete.
     */
    virtual void                forceDeleteStream(api::AStream* stream) = 0;

    /*!
     * \brief Create a new message starting at a step.
     *
     * This create a new IMessage who has the same client but a
     * new exeuction flow started on \a stepId.
     * The \a input Stream will be send to the first callback of the step,
     * and the flow will continue normaly until the end.
     * Typicaly use to start a parallel repsone (eg: 100 reponses).
     *
     * The DataRep this->mHttp will be point on the same datas.
     * But this->mHttpResp will be duplicated in the new IMessage of
     * the new message.
     *
     * \param stepId The step where to begin the new flow.
     * \param input The input AStream send on the step.
     * \return The new IMessage of the new message, its state depends on where
     * you begin your response.
     */
    virtual api::IMessage*      newMessageAtStep(api::HttpStepID stepId, api::AStream& input) = 0;

protected:
    /*!
     * \brief IConnection pointer.
     *
     * Must be set.
     */
    IConnection&                mConnection;

    /*!
     * \brief true if is parsed.
     */
    bool                        mParsed;

    /*!
     * \brief IMessage's ILog.
     *
     * Must be set.
     */
    ILog*                       mLog;

    /*!
     * \brief Request http header data representation.
     *
     * Must be set.
     */
    DataTree*                   mHttp;

    /*!
     * \brief Response http header data representation.
     *
     * Must be set.
     */
    DataTree*                   mHttpResp;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_IMESSAGE_H_ */
