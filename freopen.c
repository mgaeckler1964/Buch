/* freopen.c */
#include <stdio.h>

int main( void )
{
	if( freopen( "ausgabe.log", "w", stdout ) )
		puts( "Hallo Welt" );
	else
		fputs( "Fehler bei der Umleitung", stderr );
		
	return 0;
}


