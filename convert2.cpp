// convert2.cpp
#include <iostream>
#include <typeinfo>

struct base
{
	int b;

	virtual int getValue() const
	{
		return b;
	}
};

struct derived1 : public base
{
	int d1;

	virtual int getValue() const
	{
		return d1;
	}
};


struct derived2 : public base
{
	int d2;

	virtual int getValue() const
	{
		return d2;
	}
};


int main()
{
	derived1	d1;
	derived2	d2;

	base		*b1 = &d1;
	base		&b2 = d2;

	derived1	*dp1 = dynamic_cast<derived1*>(b1);
	derived2	*dp2 = dynamic_cast<derived2*>(b1);

	if( dp1 )
		std::cout << "Zeiger b1 erfolgreich nach derived1* konvertiert" << std::endl;
	if( !dp2 )
		std::cout << "Zeiger b1 erfolglos nach derived2* konvertiert" << std::endl;

	try
	{
		derived2	&d2 = dynamic_cast<derived2&>(b2);
		std::cout << "Referenz b2 erfolgreich nach derived2& konvertiert" << std::endl;
	}
	catch( std::bad_cast &e )
	{
	}

	try
	{
		derived1	&d1 = dynamic_cast<derived1&>(b2);
	}
	catch( std::bad_cast &e )
	{
		std::cout << "Referenz b2 erfolglos nach derived1& konvertiert" << std::endl;
	}

	return 0;
}