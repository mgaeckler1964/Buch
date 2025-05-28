/*
	timestamp1.cpp: Zeige Uhrzeit und Schaltjahr
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

struct Datum
{
	int 	tag,
			monat,
			jahr;
		
	Datum( int tag, int monat, int jahr ) : tag(tag), monat(monat), jahr(jahr)
	{
	}
	bool isLeap() const
	{
		return isLeap( jahr );
	}
	static bool isLeap( int jahr );

	void setYear( int jahr )
	{
		this->jahr = jahr;
	}
};

bool Datum::isLeap( int jahr )
{
	if( (jahr % 4) != 0 )
		return false;
	if( (jahr % 400) == 0 )
		return true;
	if( (jahr % 100) == 0 )
		return false;
		
	return true;
}

struct Zeitstempel : Datum, Zeit
{
	Zeitstempel(int tag, int monat, int jahr, int stunde, int minute, int sekunde) : 
		Datum(tag, monat, jahr), Zeit(stunde, minute, sekunde) 
	{
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

int main()
{
	Zeitstempel zeit( 11, 3, 1964, 3, 35, 0 );

	std::cout << "Lokale Uhrzeit: " << zeit.getLocalHour() << ':' << zeit.minute << ':' << zeit.sekunde << std::endl;
	std::cout << "GMT           : " << zeit.getGMThour()   << ':' << zeit.minute << ':' << zeit.sekunde << std::endl;

	std::cout << zeit.jahr << " ist " << (zeit.isLeap() ? "ein" : "kein") << " Schaltjahr." << std::endl;

	std::cout << "Jetzt wird aufgeräumt" << std::endl;
	return 0;
}
