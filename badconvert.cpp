#include <iostream>

struct ClassB;

struct ClassA
{
	int	m_x, m_y;
	
	ClassA( int x, int y=1 ) : m_x(x), m_y(y)
	{
	}

	operator double() const
	{
		return m_x * m_y;
	}
};

struct ClassB
{
	int		m_x;
	ClassA	m_a;
	
	ClassB( int x, int y, int z ) : m_x(x), m_a(y, z)
	{
	}
	
	operator double() const
	{
		return m_x * double(m_a);
	}
	operator ClassA() const
	{
		return m_a;
	}
};

int main()
{
	ClassB	b( 4, 2, 3 );
	ClassA	a( b );
	
	std::cout << double(b) << ' ' << double(a) << std::endl;
}

