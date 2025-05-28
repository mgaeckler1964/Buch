/*
	template7.cpp: show distance
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
};

template<typename ScalarT> class Point3D : public Point<ScalarT>
{
	public:
	typedef ScalarT	Scalar;

	private:
	Scalar		z;

	public:
	Point3D( Scalar x, Scalar y, Scalar z ) : Point<Scalar>(x,y), z(z)
	{
	}
	Scalar getZ() const
	{
		return z;
	}
	template<typename PointT>
	Scalar distance( const PointT &other ) const
	{
		Scalar kat1 = this->getX() - other.getX();
		Scalar kat2 = this->getY() - other.getY();

		Scalar kat3 = std::sqrt( kat1*kat1 + kat2*kat2 );
		Scalar kat4 = z - other.getZ();
		return std::sqrt( kat3*kat3 + kat4*kat4 );
	}
};

int main( void )
{
	Point3D<double>	point1(0,0,0);
	Point3D<double>	point2(1,1,1);

	std::cout << "Abstand ist " << point1.distance( point2 ) << std::endl;
}