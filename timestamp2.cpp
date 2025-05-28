/*
	timestamp2.cpp: Zeige Uhrzeit und Schaltjahr
*/

#include <iostream>

struct Zeit
{
	protected:
	static int timeZone;
	
	private:
	int stunde, minute, sekunde;
	
	public:
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
	int getMinute() const
	{
		return minute;
	}
	int getSekunde() const
	{
		return sekunde;
	}
};

struct Datum
{
	private:
	int 	tag,
			monat,
			jahr;
		
	public:
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
	int getJahr() const
	{
		return jahr;
	}
	int getDay() const
	{
		return tag;
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

class Zeitstempel : public Datum, public Zeit
{
	public:
	Zeitstempel(int tag, int monat, int jahr, int stunde, int minute, int sekunde) : 
		Datum(tag, monat, jahr), Zeit(stunde, minute, sekunde) 
	{
	}
	int getLocalDay() const
	{
		int	tag = getDay();
		int stunde = getGMThour() - timeZone;
		if( stunde < 0 )
			--tag;
		else if( stunde >= 24 )
			++tag;

		return tag;
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
	Zeitstempel zeit( 11, 3, 1964, 23, 35, 0 );

	std::cout << "Lokale Uhrzeit: " << zeit.getLocalDay() << ' ' << zeit.getLocalHour() << ':' << zeit.getMinute() << ':' << zeit.getSekunde() << std::endl;
	std::cout << "GMT           : " << zeit.getDay()      << ' ' << zeit.getGMThour()   << ':' << zeit.getMinute() << ':' << zeit.getSekunde() << std::endl;

	std::cout << zeit.getJahr() << " ist " << (zeit.isLeap() ? "ein" : "kein") << " Schaltjahr." << std::endl;

	std::cout << "Jetzt wird aufgeräumt" << std::endl;
	return 0;
}
