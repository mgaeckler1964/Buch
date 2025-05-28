// time.c - examples for <time.h>
#include <time.h>
#include <stdio.h>

static void showTime( const struct tm *theTime ) {
	char localBuffer[128];

	asctime_s( localBuffer, sizeof( localBuffer ), theTime );
	puts( localBuffer );
}

int main( void ) {
	time_t theTime = time( 0 );

	struct tm	local = *localtime( &theTime );
	struct tm	iis = *gmtime( &theTime );

	puts( "Zeit in Linz:" );
	showTime(&local);
	puts( "Zeit auf der IIS:" );
	showTime(&iis);

	return 0;
};