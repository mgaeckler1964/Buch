#include <iostream>

struct ClassB;
struct ClassA
{
	int	m_x, m_y;
	
	ClassA( int x, int y=1 ) : m_x(x), m_y(y)
	{
	}
	ClassA( const ClassB &src )
	{
		std::cout << "ClassA( const ClassB &src )\n";
		read( src );
	}
	const ClassA & operator = ( const ClassB &src )
	{
		std::cout << "const ClassA & operator = ( const ClassB &src )\n";
		read( src );
	}
	operator double() const
	{
		std::cout << "ClassA::operator double()" << std::endl;
		return m_x * m_y;
	}
	
	void read( const ClassB &src );
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
		std::cout << "ClassB::operator double()" << std::endl;
		return m_x * double(m_a);
	}
	operator ClassA() const
	{
		std::cout << "ClassB::operator ClassA()" << std::endl;
		return m_a;
	}
};

void ClassA::read( const ClassB &src )
{
	std::cout << "ClassA::read()" << std::endl;
	*this = src.m_a;
}

int main()
{
	ClassB	b( 4, 2, 3 );
	std::cout << "Declare\n";
	ClassA	a( b );
	std::cout << "Assign\n";
	a = b;
	std::cout << "Result:\n";
	std::cout << double(b) << ' ' << double(a) << std::endl;
}

