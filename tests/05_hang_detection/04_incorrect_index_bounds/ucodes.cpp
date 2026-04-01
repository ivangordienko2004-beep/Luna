#include "ucenv.h"
#include <cstdio>

extern "C" 
{
	void c_set_value_int(OutputDF &x, int value) 
	{
		x.setValue(value);
	}
}

