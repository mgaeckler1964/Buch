#include <iostream>
#include <fstream>

int main()
{
	std::ifstream	inp( "test.txt" );

	if( !inp.is_open() )
	{
		std::cout << "Erzeuge Datei" << std::endl;
		std::ofstream	out( "test.txt" );

		out << "1234" << std::endl;
		out.close();

		inp.open( "test.txt" );
	}

	int zahl;
	inp >> zahl;

	std::cout << "Die gelesene Zahl ist " << zahl << std::endl;

	return 0;
}
