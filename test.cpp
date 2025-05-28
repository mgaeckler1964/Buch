#include <iostream>

class TestClass
{
	const char	*m_text;
	int			m_number;
	
	protected:
	const char *getText() const
	{
		return m_text;
	}
	public:
	TestClass( const char *text, int number ) : m_text( text ), m_number(number)
	{
	}
	operator const char * () const
	{
		return m_text;
	}
	int getNumber() const
	{
		return m_number;
	}
};

class DerivedClass : private TestClass
{
	public:
	DerivedClass( const char *text, int number ) : TestClass( text, number )
	{
	}
#if 0
	operator const TestClass * () const
	{
		return this;
	}
#else
	operator const char * () const
	{
		return TestClass::getText();
	}
#endif
	int getNumber() const
	{
		return TestClass::getNumber();
	}

};

int main( void )
{
	TestClass		test( "Hello", 666 );
	
	if( test && test.getNumber() )
	{
		std::cout << test.getNumber() << std::endl;
	}

	DerivedClass	derived( "Hello", 123 );
	
	if( derived && derived.getNumber() )
	{
		std::cout << derived.getNumber() << std::endl;
	}
	return 0;
}