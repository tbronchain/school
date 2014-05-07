#include <vector>
#include <map>
#include <iostream>

namespace api
{
	/*! \class IModule
	* \brief interface which describes a module
	*/
	class											IModule
	{
	public:
		~IModule() {};

		enum executionTime
		{
			FIRST,
			LAST,
			ANYWHERE
		};
	/**
	* \fn executionTime getExecutionTime ()
	* \brief return the execution time
	* \return executionTime return the execution time
	*/
		virtual executionTime						getExecutionTime() = 0;

	private:
	};
}
