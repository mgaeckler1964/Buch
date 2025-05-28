/*
	pointer1.cpp: demonstration of pointer to base class
*/

#include <iostream>

class base1
{
	int value1;
};

class base2
{
	int value2;
};

class derived : public base1, public base2
{
	int value;
};

int showAddress1( const base1 &obj )
{
	std::cout << &obj << std::endl;
}

int showAddress2( const base2 &obj )
{
	std::cout << &obj << std::endl;

	const derived *ptr = &obj;

	std::cout << ptr << std::endl;
}

int showAddress3( const derived &obj )
{
	std::cout << &obj << std::endl;
}

int main( void )
{
	derived	obj;

	showAddress1( obj );
	showAddress2( obj );
	showAddress3( obj );

	return 0;
}
