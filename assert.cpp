/*
	assert.cpp: demonstration of assert
*/

#include <iostream>
#include <cassert>

static void showDigit( int ziffer )
{
	assert( ziffer >= 0 && ziffer <= 9 );
	std::cout << ziffer;
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

