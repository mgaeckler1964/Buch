/*
	exception1.cpp: example for try, catch and throw
*/

#include <iostream>
#include <exception>

static void werfer()
{
	throw std::range_error( "Eine Ausahme" );
}

int main()
{
	try
	{
		werfer();
		std::cout << "Keine Ausnahme" << std::endl;
	}
	catch( std::range_error &e )
	{
		std::cerr << "range_error: " << e.what() << std::endl;
	}
	catch( std::runtime_error &e )
	{
		std::cerr << "runtime_error: " << e.what() << std::endl;
	}
	catch( std::exception &e )
	{
		std::cerr << "exception: " << e.what() << std::endl;
		throw;
	}
	catch( ... )
	{
		std::cerr << "Unbekanter Fehler" << std::endl;
		throw;
	}

	return 0;
}