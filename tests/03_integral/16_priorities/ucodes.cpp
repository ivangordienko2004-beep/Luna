#include <cstdio>
#include "ucenv.h"

extern "C" 
{
    
	void show_double(const char *caption, double val)
	{
		printf("%s%0.2lf\n", caption, val);
	}

	void assign_double(OutputDF &df, double val)
	{
		df.setValue<double>(val);
	}

}
