// operator.cpp: demo for operator overloading
#include <iostream>

struct MyStruct
{
	int value;
	bool flag;
};

// pre increment
MyStruct operator ++ ( MyStruct &oper )
{
	++oper.value;
	return oper;
}

// post increment
MyStruct operator ++ ( MyStruct &oper, int dim )
{
	MyStruct result = oper;
	oper.value++;
	std::cout << "postfix" << dim << std::endl;
	return result;
}

int main()
{
	MyStruct	val = { 0, false };
	++val;
	val++;
	return 0;
}
