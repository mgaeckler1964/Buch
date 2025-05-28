/*
	perror.cpp: perror example
*/

#include <cstdio>
#include <fstream>
 
int main( void )
{
	std::ifstream	f( "gibts nicht" );
	if( !f.is_open() )
	{
		std::perror( "gibts nicht" );
	}

	return 0;
}
