/*
	pointer4.cpp: demonstration of pure virtual function calls
*/

#include <iostream>

class Graphic
{
	public:
	virtual void show() const = 0;
	virtual void showName() const = 0;

	virtual ~Graphic()
	{
		print();
	}

	void print()
	{
		showName();
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
		showName();
		std::cout << " (" << x << ',' << y << ')' << std::endl;
	}
	virtual void showName() const
	{
		std::cout << "Punkt";
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
	virtual void showName() const
	{
		std::cout << "Kreis";
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
