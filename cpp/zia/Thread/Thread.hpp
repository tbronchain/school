#ifndef THREAD_HPP_
# define THREAD_HPP_

# include <iostream>

# include <iostream>


template <typename T>
class AThread
{
public:
	AThread(T& instance, void (T::*pmethodRun)()) :
	  instance_(instance),
		  pmethodRun_(pmethodRun){}

	  ~AThread()
	  {
	  }

	  void runMethod()
	  {
		  ((this->instance_).*(this->pmethodRun_))();
	  }

	  /*void join()
	  {
		  this->thread_.join();
	  }*/

	  template <typename U>
	  void post(void (T::*pmethodPost)(U) , U item)
	  {
		  ((this->instance_).*(pmethodPost))(item);
	  }
private:
	T&				instance_;
	void			(T::*pmethodRun_)();
};



# ifdef _WIN32
#  include "ThreadWindows.hpp"
#  define Thread ThreadWindows
# else
#  include "ThreadUnix.hpp"
#  define Thread ThreadUnix
# endif // _WIN32

#endif // THREAD_HPP_
