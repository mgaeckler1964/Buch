/* getchar1.c */
#include <stdio.h>

int main( void )
{
	char c;

	while( 1 )
	{
		c = getchar();
		if( c == EOF )
			break;
		putchar( c );
	}

	return 0;
}
