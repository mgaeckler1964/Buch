/*
	template8.cpp: simple map
*/

#include <iostream>
#include <math.h>

template<typename ValueT, int numData=10> class Array 
{
	public:
	typedef ValueT	value_type;
	
	private:
	value_type	data[numData];
	
	public:
	void set( int index, const value_type &val )
	{
		if( index >= 0 && index < numData )
			data[index] = val;
	}
	
	value_type get( int index ) const
	{
		if( index >= 0 && index < numData )
			return data[index];
		else
			return value_type();
	}
		
};
 
template<typename KeyT, typename ValueT, template<typename, int> class ContainerT=Array, int maxNumData=10>
class Map
{
	public:
	typedef KeyT								key_type;
	typedef ValueT								value_type;
	typedef ContainerT<key_type, maxNumData>	key_container_type;
	typedef ContainerT<value_type, maxNumData>	value_container_type;
	
	private:
	key_container_type		keys;
	value_container_type	values;

	int numData;

	public:
	Map() : numData(0)
	{
	}

	void add( const key_type &key, const value_type &value )
	{
		if( numData < maxNumData-1 )
		{
			keys.set( numData, key );
			values.set( numData, value );
			++numData;
		}
	}

	value_type get( const key_type &key )
	{
		for( int i=0; i<numData; ++i )
		{
			if( keys.get( i ) == key )
				return values.get( i );
		}

		return value_type();
	}
};

int main()
{
	Map<char, double>	theMap;

	theMap.add( 'p', 3.142 );
	theMap.add( 'e', 2.718 );

	std::cout << "e=" << theMap.get( 'e' ) << std::endl;
	std::cout << "pi=" << theMap.get( 'p' ) << std::endl;
}