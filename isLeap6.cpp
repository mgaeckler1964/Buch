/*
	isLeap6.cpp: Zeige Schaltjahr
*/

#include <iostream>

class Datum
{
	public:
	enum Monate
	{
		Januar, Februar, Maerz, April, Mail, Juni, July, August, September, Oktober, November, Deember
	};

	private:
	int 	tag,
		jahr;

	Monate	monat;

	public:		
	Datum( int tag, Monate monat, int jahr ) : tag(tag), monat(monat), jahr(jahr)
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
	int getYear() const
	{
		return jahr;
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

int main( void )
{
	Datum::Monate	monat = Datum::Juni;
	Datum datum( 11, monat, 1964 );
	
	std::cout << datum.getYear() << " ist " << (datum.isLeap() ? "ein" : "kein") << " Schaltjahr." << std::endl;

	datum.setYear( 1971 );
		
	std::cout << datum.getYear() << " ist " << (datum.isLeap() ? "ein" : "kein") << " Schaltjahr." << std::endl;

	std::cout << 2016 << " ist " << (Datum::isLeap( 2016 ) ? "ein" : "kein") << " Schaltjahr." << std::endl;

	return 0;
}
