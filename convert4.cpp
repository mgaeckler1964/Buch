// convert4.cpp
#include <iostream>

struct base1
{
	int b1;
};

struct base2
{
	int b2;
};

struct derived : public base1, base2
{
	int d;
};

int main()
{
	derived	d;

	derived	*dp1 = &d;
	base1	*b1 = dp1;
	base2	*b2 = dp1;

	derived	*dp2 = static_cast<derived*>(b2);

	std::cout << dp1 << ' ' << b1 << ' ' << b2 << ' ' << dp2 << std::endl;

	return 0;
}