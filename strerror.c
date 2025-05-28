/*
	strerror.c: strerror example
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
 
static void myPerror( const char *text )
{
	fprintf( stderr, "Fehler bei %s: %s\n", text, strerror(errno) );
}

int main( void )
{
	FILE *f = fopen( "gibts nicht", "r" );
	if( NULL != f )
	{
		fclose( f );
	}
	else
	{
		myPerror( "gibts nicht" );
	}

	return 0;
}
