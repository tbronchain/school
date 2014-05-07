#ifndef _ICONNECTION_H_
#define _ICONNECTION_H_

#include "defines.hpp"
#include "Callback.hpp"
#include "AStream.hpp"
#include "DataTree.hpp"
#include "ILog.hpp"
#include "Log.h"

#if defined(_WIN32) || defined(_WIN64)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
_BOF_ZIA_API_
typedef HANDLE          Resource;
_EOF_ZIA_API_
#else
_BOF_ZIA_API_
typedef int             Resource;
_EOF_ZIA_API_
#endif

#if !defined( __ssize_t_defined )
typedef long int        ssize_t;
#endif

_BOF_ZIA_API_


/*!
 * \brief Callback used to handle FD r/w
 *
 * Return false will reset the default system r/w.
 *
 * If used to read:
 *   ssize_t  : Nbr bytes read.
 *   Resource : FD/HANDLE to read from.
 *   void*    : The buffer where to write.
 *   szie_t   : The size of the buffer.
 *
 * If used to write:
 *   ssize_t  : Nbr bytes written.
 *   Resource : FD/HANDLE to write in.
 *   void*    : The buffer where to read from.
 *   szie_t   : The size of the buffer.
 *
 */
typedef zia::api::Callback< ssize_t (Resource, void*, size_t) >     FdCallback;

/*!
 * \brief Connection class.
 *
 * IConnection represent the connection.
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// Non-virtual IMessage members to implement:
//
api::DataTree&              IConnection::info();
api::ILog&                  IConnection::log();

//
// Minimal IMessage inherits implementation:
//
namespace zia {

class X : public api::IConnection
{
public:
    X();
    virtual ~X();

    virtual void                close();
    virtual void                setFdReadCallback(api::FdCallback callback = api::FdCallback());
    virtual void                setFdWriteCallback(api::FdCallback callback = api::FdCallback());

};

}

 * \endcode
 */
class IConnection
{
public:
    IConnection()
        : mLog(0), mInfos(0)
    { };
    virtual ~IConnection() { };

    IConnection(const IConnection& aconnection)
		: mLog(aconnection.mLog), mInfos(aconnection.mInfos)
	{

	}

	IConnection&                operator=(const IConnection& aconnection)
	{
		if (this != &aconnection)
		{
			this->mLog = aconnection.mLog;
			this->mInfos = aconnection.mInfos;
		}
		return (*this);
	}

    /*!
     * \brief Get connection infos.
     *
     * Inforamtions about connection.
     */
    zia::api::DataTree&              info()
	{
		if (this->mInfos == NULL)
			this->mInfos = new DataTree();
		return (*(this->mInfos));
	}

    /*!
     * \brief Get the ILog.
     *
     * Log about the connection.
     */
    zia::api::ILog&                  log()
	{
		if (this->mLog == NULL)
			this->mLog = new Log();
		return (*(this->mLog));
	}

    /*!
     * \brief Close the connection.
     *
     */
    virtual void                close() = 0;

    /*!
     * \brief Set the input fd callback for reading.
     *
     * The FdCallback \a callback will be called when there
     * will be activity on the input FD of this message. Then,
     * the callback will read on the FD and write in the stream
     * recieved as an argument.
     *
     * \param callback The callback. Dont specify it to unset the callback.
     */
    virtual void                setFdReadCallback(api::FdCallback callback = api::FdCallback()) = 0;

    /*!
     * \brief Set the output fd callback for writing.
     *
     * The FdCallback \a callback will be called when the FD
     * will be available for writing. Then, the callback
     * will read on the stream and write on the FD.
     *
     * \param callback The callback. Dont specify it to unset the callback.
     */
    virtual void                setFdWriteCallback(api::FdCallback callback = api::FdCallback()) = 0;

protected:
    /*!
     * \brief IConnection's ILog.
     *
     * Must be set.
     */
    ILog*                       mLog;

    /*!
     * \brief DataRep connection inforamtions.
     *
     * Must be set.
     */
    DataTree*                   mInfos;

};

_EOF_ZIA_API_

#endif /* _ICONNECTION_H_ */
