/* ratio.cpp - demonstration of ratio template */
#include <iostream>
#include <ratio>

template <typename FROM, typename TO>
double convert( double value ) {
	value *= double(FROM::num) / double(TO::num);
	value *= double(TO::den) / double(FROM::den);
	return value;
}

int main() {
	double source = 1;

	double target = convert<std::kilo, std::milli>( source );
	std::cout << source << ' ' << target << std::endl;

	target = convert<std::kilo, std::mega>( source );
	std::cout << source << ' ' << target << std::endl;

	target = convert<std::kilo, std::ratio<1> >( source );
	std::cout << source << ' ' << target << std::endl;

	return 0;
}