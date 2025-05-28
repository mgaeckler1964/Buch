/*
	pointer3.cpp: demonstration of abstract classes
*/

#include <iostream>

class Graphic
{
	public:
	virtual void show() const = 0;
	virtual ~Graphic()
	{
	}
};

class Punkt : public Graphic
{
	double x, y;

	public:
	Punkt( double x, double y ) : x(x), y(y)
	{
	}

	virtual void show() const
	{
		std::cout << "Punkt (" << x << ',' << y << ')' << std::endl;
	}
};

class Kreis : public Punkt
{
	double r;

	public:
	Kreis( double x, double y, double r ) : Punkt(x, y), r(r)
	{
	}

	virtual void show() const
	{
		Punkt::show();
		std::cout << "Radius " << r << std::endl;
	}
};

void showObject( const Graphic &obj )
{
	obj.show();
}

int main( void )
{
	Punkt	punkt( 2, 3 );
	Kreis	kreis( 5, 6, 1 );

	showObject( punkt );
	showObject( kreis );

	return 0;
}
