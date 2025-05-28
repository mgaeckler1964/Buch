/* gets1.c */
#include <stdio.h>

int main( void )
{
	char text[80];

	puts( "Wie heißen Sie?" );
	if( gets( text ) )
	{
		puts( "Hallo " );
		puts( text );
	}

	return 0;
}
