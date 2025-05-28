/*
	time6.cpp: Zeige Uhrzeit
*/

#include <iostream>

class Zeit
{
	friend class Kalender;
	friend void show(const Zeit &meineZeit);

	int stunde, minute, sekunde;
	
	public:
	Zeit( int stunde, int minute, int sekunde );

	int getHour() const
	{
		return stunde;
	}
	int getMinute() const
	{
		return minute;
	}
	int getSekunde() const
	{
		return sekunde;
	}
};

Zeit::Zeit( int stunde, int minute, int sekunde ) : stunde(stunde), minute(minute), sekunde(sekunde)
{
}

class Kalender
{
	Zeit	meineZeit;

	public:
	Kalender( int stunde, int minute, int sekunde ) : meineZeit( stunde, minute, sekunde )
	{
	}
	Kalender( const Zeit &zeit ) : meineZeit( zeit )
	{
	}
	void show( void )
	{
		std::cout << meineZeit.stunde << ':' << meineZeit.minute << ':' << meineZeit.sekunde << std::endl;
	}
};

void show(const Zeit &meineZeit)
{
	std::cout << meineZeit.stunde << ':' << meineZeit.minute << ':' << meineZeit.sekunde << std::endl;
}

int main( void )
{
	Zeit uhrZeit( 3, 35, 0 );
	Kalender kalender( uhrZeit );

	kalender.show();
	show( uhrZeit );

	return 0;
}
