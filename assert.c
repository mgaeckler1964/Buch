/*
	assert.c: demonstration of assert
*/

#include <stdio.h>
#include <assert.h>

static void showDigit( int ziffer )
{
	assert( ziffer >= 0 && ziffer <= 9 );
	printf( "%d", ziffer );
}

int main( void )
{
	showDigit( 1 );
	showDigit( 9 );
	showDigit( 6 );
	showDigit( 4 );
	showDigit( 1964 );

	return 0;
}

