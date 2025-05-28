#include <stdio.h>

#include "const.h"

const int c = 123;
const char *text = "Hello world";
const char * const format = "c=%d text=%s\n";

int main()
{
	printf( format, c, text );

	int test = getConst();

	if( test == constValue && getConstAddr() == &constValue )
	{
		text = "Neuer Text";
		printf( format, constValue, text );
	}
	else
	{
		printf( "%p %p\n", getConstAddr(), &constValue );
	}
#if 0
	format = "text=%s c=%d\n";
	c = 125;
	*text = 'A';
	printf( format, text, c );
#endif

	return 0;
}
