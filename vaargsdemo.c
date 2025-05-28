// vaargsdemo.c: va_args demonstration
#include <stdio.h>
#include <stdarg.h>

int superfunc( int oper, ... ) {
	va_list	args;
	int 	result = oper;
	va_start( args, oper );
	while( 1 ) {
		int operand = va_arg( args, int );
		if( !operand )
			break;
		if( oper )
			result *= operand;
		else
			result += operand;
	}
	va_end(args);
	return result;
}

int main( void ) {
	int result1 = superfunc( 1, 1, 2, 3, 4, 5, 0 );
	int result2 = superfunc( 0, 1, 2, 3, 4, 5, 0 );
	printf( "%d %d\n", result1, result2 );
	return 0;
}
