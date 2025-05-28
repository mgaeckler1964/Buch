/*
	time5.cpp: Zeige Uhrzeit
*/

#include <iostream>

struct Zeit
{
	static int timeZone;
	
	int stunde, minute, sekunde;
	
	Zeit( int stunde, int minute, int sekunde );
	~Zeit();
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

Zeit::Zeit( int stunde, int minute, int sekunde ) : stunde(stunde), minute(minute), sekunde(sekunde)
{
}

Zeit::~Zeit()
{
	std::cout << "Auf wiedersehen" << std::endl;
}

int Zeit::timeZone = -1;

int main( void )
{
	Zeit uhrZeit( 3, 35, 0 );
	
	std::cout << "Lokale Uhrzeit: " << uhrZeit.getLocalHour() << ':' << uhrZeit.minute << ':' << uhrZeit.sekunde << std::endl;
	std::cout << "GMT           : " << uhrZeit.getGMThour()   << ':' << uhrZeit.minute << ':' << uhrZeit.sekunde << std::endl;
	
	std::cout << "Jetzt wird aufgeräumt" << std::endl;
	return 0;
}
