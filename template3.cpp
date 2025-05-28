/*
	template3.cpp: show distance
*/

#include <iostream>
#include <cmath>

template<typename ScalarT> class Point
{
	public:
	typedef ScalarT	Scalar;

	private:
	Scalar		x, y;

	public:
	Point( Scalar x, Scalar y ) : x(x), y(y)
	{
	}

	Scalar distance( const Point &other ) const
	{
		Scalar kat1 = x - other.x;
		Scalar kat2 = y - other.y;

		return std::sqrt( kat1*kat1 + kat2*kat2 );
	}
};

int main( void )
{
	Point<float>	point1(0,0);
	Point<float>	point2(1,1);

	std::cout << "Abstand ist " << point1.distance( point2 ) << std::endl;
}