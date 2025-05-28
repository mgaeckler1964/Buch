/*
	perror.c: perror example
*/

#include <stdio.h>
 
int main( void )
{
	FILE *f = fopen( "gibts nicht", "r" );
	if( NULL != f )
	{
		fclose( f );
	}
	else
	{
		perror( "gibts nicht" );
	}

	return 0;
}
