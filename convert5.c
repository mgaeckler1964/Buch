/* convert5.c */
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	{
		const char *integerString = "123456ABCD";

		int i = atoi( integerString );

		printf( "Es wurde %d eingegeben\n", i );
	}
	{
		const char *integerString = "1234ABCD";
		char *endPtr;

		long i = strtol( integerString, &endPtr, 10 );

		printf( "Es wurde %ld eingegeben\n", i );
		printf( "Falsches Zeichen %c\n", *endPtr );

		i = strtol( integerString, &endPtr, 16 );

		printf( "Es wurde %lx eingegeben\n", i );
		if( *endPtr )
			printf( "Falsches Zeichen %c\n", *endPtr );
	}
	{
		const char *floatString = "-1234.5678e-10";

		double d = atof( floatString );

		printf( "Es wurde %lg eingegeben\n", d );
	}
	{
		const char *floatString = "-1234.5678e-10ABCD";
		char *endPtr;

		double d = strtod( floatString, &endPtr );

		printf( "Es wurde %lg eingegeben\n", d );
		printf( "Falsches Zeichen %c\n", *endPtr );
	}

	return 0;
}