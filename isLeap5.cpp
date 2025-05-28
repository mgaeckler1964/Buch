/*
	isLeap5.cpp: Zeige Schaltjahr
*/

#include <iostream>

struct Datum
{
	int 	tag,
		monat,
		jahr;
		
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

int main( void )
{
	Datum datum = { 11, 6, 1964 };
	
	std::cout << datum.jahr << " ist " << (datum.isLeap() ? "ein" : "kein") << " Schaltjahr." << std::endl;

	datum.setYear( 1971 );
		
	std::cout << datum.jahr << " ist " << (datum.isLeap() ? "ein" : "kein") << " Schaltjahr." << std::endl;

	std::cout << 2016 << " ist " << (Datum::isLeap( 2016 ) ? "ein" : "kein") << " Schaltjahr." << std::endl;

	return 0;
}
