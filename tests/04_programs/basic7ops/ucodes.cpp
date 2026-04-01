#include <cstdio>
#include <cstring>

extern "C" 
{
	void c_hello(const char *x) 
	{
		if(strlen(x)>0) {
			printf("Hello, %s!\n", x);
		} else {
			printf("Hello!\n");
		}
	}
}