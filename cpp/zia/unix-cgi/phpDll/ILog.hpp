#ifndef _ZIA_API_ILOG_H_
#define _ZIA_API_ILOG_H_

#include <sstream>
#include <iostream>

#include "defines.hpp"

_BOF_ZIA_API_


/*!
 * \brief Log levels
 */
enum LogLevel
{
    LOG_ASSERT = 1,
    LOG_ERR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
    LOG_DEBUG2
};


/*!
 * \brief Log class
 *
 * <h2> Zia core implementations: </h2>
 * \code

//
// ILog implementation:
//
ILog::ILog();
ILog::~ILog();
ILog&           operator << (std::ostream& (*pf)(std::ostream&));

//
// Minimal ILog inherits implementation:
//
namespace zia {

class X : public api::ILog
{
public:
    X();
    virtual ~X();

    virtual api::ILog&  operator << (api::LogLevel level);
    virtual void        flush();
    virtual void        print(api::LogLevel level, const std::string& format, ...);

    using api::ILog::operator <<;

};

}

 * \endcode
 *
 */
class ILog
{
public:

    /*!
     * \brief Constructor.
     */
	ILog() {}
    /*!
     * \brief Copy constructor.
     *
     */
    ILog(const ILog& ilog)
	{

	}

    /*!
     * \brief Destructor.
     */
	virtual ~ILog() {}

    /*!
     * \brief Manipulators.
     *
     * if (pf == std::endl) flush();
     */
    ILog&               operator << (std::ostream& (*pf)(std::ostream&))
	{
		//if (pf == std::endl)
			//flush();
		return (*this);
	}

    /*!
     * \brief C++ output stream like.
     *
     * This is a template because it permits to work
     * automativaly with every type:
     *
     * eg:
     * \code

log << "toto";  // automaticaly: operator << ( const char[4] & input )
log << 42;      // automaticaly: operator << ( const int & input )
log << 18.5;    // automaticaly: operator << ( const double & input )

     * \endcode
     */
    template <typename T>
    ILog&               operator << (const T& input)
    {
        this->mLine << input;
        return (*this);
    }

    /*!
     * \brief Set the current log level.
     *
     * Begin your line of log with it.
     *
     * eg:
     * \code

log << ILog::DEBUG << "coucou " << 42 << std::endl;
log << ILog::ERROR << "poney " << 273 << std::endl;

     * \endcode
     */
    virtual api::ILog&  operator << (api::LogLevel level) = 0;

    /*!
     * \brief Flush line.
     *
     * Print the mLine in the real log (cout, cerr, file ...).
     */
    virtual void        flush() = 0;

    /*!
     * \brief Printf like.
     *
     * \param level The api::LogLevel.
     * \param format The format string for printf.
     * \param ... Values corresponding to the format.
     */
    virtual void        print(api::LogLevel level, const char* format, ...) = 0;

protected:
    /*!
     * \brief Log buffer.
     */
    std::stringstream   mLine;

};

_EOF_ZIA_API_

#endif /* _ZIA_API_ILOG_H_ */
