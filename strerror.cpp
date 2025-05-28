/*
	strerror.cpp: strerror example
*/

#include <cstring>
#include <cerrno>
#include <iostream>
#include <fstream>

static void myPerror( const char *text )
{
	std::cerr << "Fehler bei " << text << ": " << std::strerror(errno) << std::endl;
}

int main( void )
{
	std::ifstream	f( "gibts nicht" );
	if( !f.is_open() )
	{
		myPerror( "gibts nicht" );
	}

	return 0;
}
