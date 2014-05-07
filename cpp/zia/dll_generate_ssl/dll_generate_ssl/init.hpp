#ifndef _INITDLL_H_
#define _INITDLL_H_

#include <list>

#include "IModule.hpp"
#include "IConf.hpp"
#include "HttpStep.hpp"
#include "AStream.hpp"

#if defined(_WIN32) || defined(_WIN64)
#  define ZIA_INIT_EXPORT       __declspec(dllexport)
#else
#  define ZIA_INIT_EXPORT
#endif

extern "C"
{

    /*!
     * \brief First called function of the DLL.
     *
     * Can be used to initialize global datas.
     *
     * \param conf The IConf of the Zia server.
     * \param log The ILog.
     */
    ZIA_INIT_EXPORT void                dll_load(zia::api::IConf& conf,
                                                 zia::api::ILog& log);

    /*!
     * \brief Function called when new connection.
     *
     * Typicaly used to allocated an IModule and set HttpStep callbacks.
     *
     * \param stepsCallbacks The list to fill with HttpStep::Pair.
     * \param conf The IConf of the Zia server.
     * \param connection The IConnection.
     * \return a IModule pointer that will be used by the server,
     * 0 if you dont want to use your module for this request.
     */
    ZIA_INIT_EXPORT zia::api::IModule*  module_new(std::list<zia::api::HttpStep::Pair>& stepsCallbacks,
                                                   zia::api::IConnection& connection,
                                                   zia::api::IConf& conf);

    /*!
     * \brief Function called when unloading the dll.
     *
     * \param log The ILog.
     */
    ZIA_INIT_EXPORT void                dll_unload(zia::api::ILog& log);

}

#endif /* _INITDLL_H_ */
