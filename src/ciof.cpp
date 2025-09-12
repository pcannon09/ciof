#include "../inc/ciof/ciof.hpp"

#ifndef __CIOF_OK
# 	error "CIOF Is not OK, make sure to not have any errors at compile time"
#endif // NOT : __CIOF_OK

namespace ciof
{
	CIOFOutputConfig outputConf;

	void print()
	{ std::cout << std::endl; }
}
