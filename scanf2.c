/* scanf2.c */
#include <stdio.h>

static void leerePuffer( void )
{
	int c;
	while( (c=getchar()) != EOF && c != '\n' )
		;
}

static int eingabe( const char *prompt )
{
	int		eingabeWert;
	char	abschluss;
	int		scanfWert;

	puts( prompt );

	while( 1 )
	{
		scanfWert = scanf( "%d%c", &eingabeWert, &abschluss );
		if( scanfWert == EOF )
		{
			eingabeWert = -1;
			break;
		}
		else if( !scanfWert || eingabeWert < 0 || abschluss != '\n' )
		{
			puts( "Sie haben einen falschen Wert eingegeben!" );
			leerePuffer();
		}
		else
			break;
	}

	return eingabeWert;
}

int main( void )
{
	int 	alter;

	alter = eingabe( "Wie alt sind Sie?" );

	if( alter >= 0 )
		printf( "Sie sind also %d Jahre alt.\n", alter );
	else
		puts( "Spielverderber" );

	return 0;
}
