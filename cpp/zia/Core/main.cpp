//
#include <iostream>
#include "Controller.h"

int		main()
{
	unsigned int lim_fd = 0;

#ifdef _WIN32
	lim_fd = SOMAXCONN > MAX_CON ? MAX_CON : SOMAXCONN;
#else
	lim_fd = 1024;
#endif
	Controller ctrl(lim_fd);
        ctrl.runServer();
}
