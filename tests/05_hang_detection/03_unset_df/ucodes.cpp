#include "ucenv.h"
#include <cstdio>

extern "C" 
{
	void c_print_int(int value) 
	{
		printf("%d\n", value);
	}
}

