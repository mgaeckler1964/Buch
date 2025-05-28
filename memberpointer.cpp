// memberpointer.cpp: example for pointer to member functions od a class
#include <iostream>

class MyClass {
	int c;
	int (MyClass::*m_funcPtr)(int, int);

	int add( int a, int b ) {
		return a+b+c;
	}
	int multiply( int a, int b ) {
		return a*b*c;
	}

	public:
	MyClass( int c ) : c(c), m_funcPtr(&MyClass::add) {}
	int perform( int a, int b ) {
		return (this->*m_funcPtr)(a,b);
	}
};

int main ( void ) {
	MyClass	object( 4 );
	int result = object.perform( 5, 11 );
	std::cout << result;

	return 0;
}