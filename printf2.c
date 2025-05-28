/* printf2.c */
#include <stdio.h>

int main( void )
{
	int			i, breite = 20;

	double		pi = 3.14159265358979323846;
	double		zahlen[] =
	{
		5.256,
		3.14159265358979323846,
		2.71828182845904523536,
		10768.5478,
		1000
	};

	for( i=0; i<10; ++i )
	{
		printf( "%20f %20g %20e\n", pi, pi, pi );

		pi *= 10;
	}

	pi = 3.14159265358979323846;
	for( i=0; i<10; ++i )
	{
		printf( "%*f %*g %*e\n", breite, pi, breite, pi, breite, pi );

		pi /= 10;
	}

	pi = 3.14159265358979323846;
	for( i=0; i<10; ++i )
		printf( "%.*f\n", i, pi );

	for( i=0; i<sizeof( zahlen ) / sizeof zahlen[0]; ++ i )
		printf( "%20.3f %20g %#20g\n", zahlen[i], zahlen[i], zahlen[i] );

	return 0;
}

