#include <iostream>

template <typename TYPE>
int perform( const TYPE &proc, int param )
{
    return proc( param );
}

int main()
{
    int result;
    int capture = 2;
    int ret = perform(
        [=, &result](int param) -> int {
			result = param * capture;
            return result;
        }, 4
    );
    
    std::cout << ret << ' ' << result;
    return 0;
}