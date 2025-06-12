// chrono.cpp - demo for <chrono>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>

static volatile int sink; // prevents optimization

static void do_some_work(std::size_t size)
{
	std::vector<int> v(size, 42);
	sink = std::accumulate(v.begin(), v.end(), 0); // ensures side effect
}

int main()
{
	std::cout << std::fixed << std::setprecision(9) << std::left;
	for (unsigned long long size = 1ull; size < 100000000ull; size *= 100)
	{
		const std::chrono::utc_clock::time_point start = std::chrono::utc_clock::now();
		do_some_work(size);
		const std::chrono::utc_clock::time_point end = std::chrono::utc_clock::now();
		const std::chrono::duration<double> diff = end - start;
		std::cout << "start = " << start << "; end = " << end << ";\n";
		std::cout << "diff = " << diff << "; size = " << size << '\n';
	}
}