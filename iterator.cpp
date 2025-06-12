// iterator.cpp: demo of how to use an iterator
#include <deque>
#include <iterator>
#include <iostream>

int main ( void )
{
	typedef std::deque<int>							MyContainer;
	typedef MyContainer::const_iterator				IntConstIT;
	typedef std::front_insert_iterator<MyContainer>	IntFrontIT;
	typedef std::insert_iterator<MyContainer>		IntInserter;
	typedef std::back_insert_iterator<MyContainer>	IntApendIT;

    MyContainer v;
	
	std::cout << "----Step 1------" << std::endl;
	IntApendIT	back = std::back_inserter<MyContainer>(v);

	*back = 1;
	*back = 2;
	*back = 3;

	for( IntConstIT it = v.cbegin(); it != v.cend(); ++it )
		std::cout << *it << std::endl;

	std::cout << "----Step 2------" << std::endl;
	IntInserter ins = std::inserter<MyContainer>(v, ++v.begin() );
	*ins = 4;
	*ins = 5;
	*ins = 6;

	for( IntConstIT it = v.cbegin(); it != v.cend(); ++it )
		std::cout << *it << std::endl;

	std::cout << "----Step 3------" << std::endl;
	IntFrontIT front = std::front_inserter<MyContainer>(v);
	*front = 7;
	*front = 8;
	*front = 9;

	for( IntConstIT it = v.cbegin(); it != v.cend(); ++it )
		std::cout << *it << std::endl;

	std::cout << "----END---------" << std::endl;

	return 0;
}