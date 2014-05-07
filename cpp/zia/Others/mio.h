#ifndef MIO_H_
# define MIO_H_

# ifdef _WIN32
#  include <io.h>
#  define READ	_read
#  define WRITE	_write
#  define CLOSE	_close
# else
#  define READ	read
#  define WRITE	write
#  define CLOSE	close
# endif // !_WIN32

#endif // !MIO_H_
