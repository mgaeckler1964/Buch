/* printf1.c */
#include <stdio.h>

int main( void )
{
	char		zeichen = 'A';
	int			zahl = 4711;
	unsigned	oktal = 4711;
	const char	*text = "Guten Abend";
	double		pi = 3.14;

	printf( "zeichen = %c\n", zeichen );
	printf( "zahl = %d\n", zahl );
	printf( "oktal = %o\n", oktal );
	printf( "text = %s\n", text );
	printf( "pi = %f\n", pi );

	return 0;
}