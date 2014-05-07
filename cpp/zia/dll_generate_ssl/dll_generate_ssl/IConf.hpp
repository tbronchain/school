#ifndef _ZIA_API_ICONF_H_
#define _ZIA_API_ICONF_H_

#include <string>

#include "defines.hpp"
#include "DataTree.hpp"
#include "ILog.hpp"

_BOF_ZIA_API_

/*!
 * \brief Zia server conf
 *
 * Represent the Configuration of the Zia server.
 * Contains conf file datas and internals configurations.
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// Minimal IConf inherits implementation:
//
namespace zia {

class X : public api::IConf
{
public:
    X();
    virtual ~X();
};

}

 * \endcode
 */
class IConf : public api::DataTree
{
public:

    /*!
     * \brief Constructor
     *
     */
    IConf() { }

    /*!
     * \brief Destructor.
     */
    virtual ~IConf() { }

};

_EOF_ZIA_API_

#endif /* _ZIA_API_ICONF_H_ */
