#ifndef _ZIA_API_IMODULE_H_
#define _ZIA_API_IMODULE_H_

#include "defines.hpp"
#include "IMessage.hpp"
#include "Callback.hpp"
#include "HttpStep.hpp"

_BOF_ZIA_API_

/*!
 * \brief Zia Module instance.
 *
 * Principaly use to represent the instance of a module,
 * you can inherit from it and code any callback inside.
 *
 * An IModule instance will be keep along the life of
 * a message.
 *
 * If you want to keep data beetween messages, you can
 * singleton or globals insinde your module
 * (the function ziaApi_init can help you).
 *
 * <h2> Zia module implementations: </h2>
 * \code

class MyModule : public zia::api::IModule
{
public:
    MyModule();
    virtual MyModule();

    virtual void        module_delete(api::IConnection& connection);

// Anything you want !!,
// All is based on HttStep::Callback and AStream::Reader

};

 * \endcode
 */
class IModule
{
public:
    /*!
     * \brief Constructor.
     */
    IModule() { }

    /*!
     * \brief Destructor.
     */
    virtual ~IModule() { }

    /*!
     * \brief Called to delete this.
     *
     * Can be called at any time. (But after disconnection).
     *
     * \param connection The closed connection.
     */
    virtual void        module_delete(api::IConnection& connection) = 0;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_IMODULE_H_ */
