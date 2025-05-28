/* const2.c */
#include "const.h"

const int getConst( void )
{
	return constValue;
}

const int *getConstAddr( void )
{
	return &constValue;
}