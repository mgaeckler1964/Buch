/*
	template6.cpp: show distance
*/

#include <iostream>
#include <cmath>

template<typename ScalarT=double> class Point
{
	public:
	typedef ScalarT	Scalar;

	private:
	Scalar		x, y;

	public:
	Point( Scalar x, Scalar y ) : x(x), y(y)
	{
	}
	Scalar getX() const
	{
		return x;
	}
	Scalar getY() const
	{
		return y;
	}
	template<typename PointT>
	Scalar distance( const PointT &other ) const
	{
		Scalar kat1 = x - other.getX();
		Scalar kat2 = y - other.getY();

		return std::sqrt( kat1*kat1 + kat2*kat2 );
	}
};

template<> class Point<int>
{
	public:
	typedef int	Scalar;

	private:
	Scalar		x, y;

	public:
	Point( Scalar x, Scalar y ) : x(x), y(y)
	{
	}
	Scalar getX() const
	{
		return x;
	}
	Scalar getY() const
	{
		return y;
	}
	template<typename PointT>
	double distance( const PointT &other ) const
	{
		double kat1 = x - other.getX();
		double kat2 = y - other.getY();

		return std::sqrt( kat1*kat1 + kat2*kat2 );
	}
};

int main( void )
{
	Point<int>	point1(0,0);
	Point<int>	point2(1,1);

	std::cout << "Abstand ist " << point1.distance( point2 ) << std::endl;
}