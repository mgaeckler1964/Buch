/* fread.c */
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

#define DATEINAME	"letzteAngabe.dat"

int main( void )
{
	int 	alter,
			letztesAlter;

	FILE	*fp = fopen( DATEINAME, "rb" );
	if( fp )
	{
		if( fread( &letztesAlter, sizeof( letztesAlter ), 1, fp ) != 1 )
		{
			puts(
				"Dateiformat von " DATEINAME " fehlerhaft.\n"
				"Datei wird ignoriert."
			);
			letztesAlter = 0;
		}

		fclose( fp );
	}
	else
		letztesAlter = 0;

	alter = eingabe( "Wie alt sind Sie?" );
	if( alter >= 0 )
	{
		printf( "Sie sind also %d Jahre alt.\n", alter );
		if( alter < letztesAlter )
			puts( "Sie Schlingel! Jungbrunnen erfunden?" );
		else if( alter > letztesAlter )
		{
			FILE	*fp = fopen( DATEINAME, "wb" );
			if( fp )
			{
				if( fwrite( &alter, sizeof( alter ), 1, fp ) != 1 )
					puts(
						"Datei " DATEINAME " konnte nicht geschrieben werden.\n"
						"Festplatte voll?"
					);

				fclose( fp );
			}
			else
				puts( "Datei " DATEINAME " konnte nicht erstellt werden." );
		}
	}
	else
		puts( "Spielverderber" );

	return 0;
}
