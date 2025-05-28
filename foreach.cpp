// forEach.cpp - demonstration of a range based for loop
#include <iostream>
#include <vector>
int main ( void ) {
	std::vector<int> v = { 1, 2, 3 };
	for( int &i : v ) {
		std::cout << i << std::endl;
		i *= 2;
	}
	for( const int &i : v ) {
		std::cout << i << std::endl;
	}
	return 0;
}
