/*
	time1.cpp: Zeige Uhrzeit
*/

#include <iostream>

struct Zeit
{
	static int timeZone;
	
	int stunde, minute, sekunde;
	
	int getLocalHour() const
	{
		int stunde = this->stunde - timeZone;
		if( stunde < 0 )
			stunde += 24;
		else if( stunde >= 24 )
			stunde -= 24;
			
		return stunde;
	}
	int getGMThour() const
	{
		return stunde;
	}
};

int Zeit::timeZone = -1;

int main( void )
{
	Zeit uhrZeit = { 3, 35, 0 };
	
	std::cout << "Lokale Uhrzeit: " << uhrZeit.getLocalHour() << ':' << uhrZeit.minute << ':' << uhrZeit.sekunde << std::endl;
	std::cout << "GMT           : " << uhrZeit.getGMThour()   << ':' << uhrZeit.minute << ':' << uhrZeit.sekunde << std::endl;
	
	return 0;
}
