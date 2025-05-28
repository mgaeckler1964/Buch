// copyc.cc: demonstration how to define and use a copy constructor
#include <iostream>
struct MyStruct {
	int val;
	//MyStruct( myStruct src ); error
	MyStruct( int val ) : val(val){
	}
	MyStruct( MyStruct &src ) : val(src.val){
	}
};

int main( void )
{
	MyStruct hello(1990);
	hello.val = 1964;
	MyStruct world1( hello );
	MyStruct world2 = hello;
	std::cout << world1.val << ' ' << world2.val;
	return 0;
}
