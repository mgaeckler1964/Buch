/* stdio.c */
#include <stdio.h>

int puts( const char *str )
{
	int result = fputs( str, stdout );

	if( result != EOF )
		result = fputc( '\n', stdout );

	return result;
}

int putchar( int c )
{
	return fputc( stdout, c );
}

int getchar( void )
{
	return fgetc( stdin );
}

