/* scanf1.c */
#include <stdio.h>

int main( void )
{
	int alter;

	puts( "Wie alt sind Sie?" );
	scanf( "%d", &alter );
	printf( "Sie sind also %d Jahre alt.\n", alter );

	return 0;
}
