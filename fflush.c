/* fflush.c */
#include <stdio.h>

static char *getline( char *data, size_t size )
{
	int c;
	int i = 0;

	if( !data || !size )
		return NULL;

	size--;				// platz für das 0 byte
	while( i<size )		// wenn zuviel Zeichen abbruch
	{
		c = getchar();
		if( c == EOF || c == '\n' )
			break;
		data[i++] = (char)c;
	}

	/*
		 wenn ende und noch nichts eingegeben wurde,
		 signalisieren wir dies durch NULL
	*/
	if( c == EOF && !i )
		return NULL;

	// Schreiben des 0 bytes
	data[i] = 0;

	return data;
}

int main( void )
{
	char text[80];

	printf( "%s", "Wie heißen Sie? " );
	fflush( stdout );
	if( getline( text, sizeof( text ) ) )
		printf( "%s %s\n", "Hallo", text );

	return 0;
}
