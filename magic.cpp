#include <iostream>
#include <fstream>
#include <cstdint>

struct DATA {
	int64_t	value;
};

int main( ) {
	int16_t	magic = 0x1234;
	int16_t size = sizeof( DATA );
	DATA	data;

	data.value = 12345678;

	{
		std::ofstream	myFile("temp.gak", std::ios_base::binary);

		myFile.write( reinterpret_cast<const char *>(&magic), sizeof( magic ) );
		myFile.write( reinterpret_cast<const char *>(&size), sizeof( size ) );
		myFile.write( reinterpret_cast<const char *>(&data), sizeof( data ) );
	}
	{
		int16_t	new_magic;
		int16_t new_size;
		DATA	new_data;
		std::ifstream	myFile("temp.gak", std::ios_base::binary);

		myFile.read( reinterpret_cast<char *>(&new_magic), sizeof( new_magic ) );
		if( new_magic == 0x3412 ) {
			std::cerr << "Falsche Endianess" << std::endl;
		}
		else if( new_magic != magic ) {
			std::cerr << "Falsches Magic" << std::endl;
		}
		else {
			myFile.read( reinterpret_cast<char *>(&new_size), sizeof( new_size ) );
			if( size != new_size ) {
				std::cerr << "Falsche Größe" << std::endl;
			}
			else {
				myFile.read( reinterpret_cast<char *>(&new_data), sizeof( new_data ) );
				std::cout << "Gefunden: " << new_data.value << std::endl;
			}
		}
	}
	return 0;
}	
