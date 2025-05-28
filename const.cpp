#include <cstdio>

class ConstExample
{
	static const int c = 123;
	static const char * const text = "Hello world";
	static const char * const format = "c=%d &c=%p text=%s\n";

	public:
	static int main()
	{
		std::printf( format, c, &c, text );

	#if 0
		format = "text=%s c=%d\n";
		c = 125;
		*text = 'A';
		printf( format, text, c );
	#endif

		return 0;
	}
};

int main()
{
	return ConstExample::main();
}
