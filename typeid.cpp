#include <iostream>
#include <typeinfo>
#include <string>


struct Sx
{
	int s;
};

struct S
{
	int s;
};

struct SuperTolleClasse
{
	int s;
};


template <typename T>
int show( void )
{
	T i;

	const std::type_info &i1 = typeid( T );
	const std::type_info &i2 = typeid( i );


	std::cout << i1.name() << '/' << std::endl;
	std::cout << i2.name() << '/' << std::endl;

}

int main( void )
{
	show<int>();
	show<signed int>();
	show<unsigned int>();
	show<bool>();
	show<Sx>();
	show<S>();
	show<SuperTolleClasse>();
	show<std::string>();
}
