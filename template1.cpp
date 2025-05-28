/*
	template1.cpp: show max value
*/

#include <iostream>

template <typename T> T maxValue( T data[], int numData )
{
	T max = 0;

	for( int i=0; i<numData; i++ )
	{
		if( max < data[i] )
			max = data[i];
	}

	return max;
}

int main( void )
{
	int intArray[] = { 0, 5, 2, 6, 9, 10, 1, 3 };
	double doubleArray[] = { 2.12, 3.14, 99.09, 5.34 };

	std::cout << "max von intArray = " << maxValue<int>( intArray, sizeof(intArray) / sizeof(intArray[0]) ) << std::endl;
	std::cout << "max von doubleArray = " << maxValue( doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]) ) << std::endl;

	return 0;
}