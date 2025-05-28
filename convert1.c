/* convert1.c */
#include <stdio.h>

int main( void )
{
	#ifndef __cplusplus
	/*
		enums <-> int
	*/
	{
		enum Test
		{
			HELLO, WORLD
		} enumVal = WORLD;
		int iVal = enumVal;
		enum Test eVal = iVal;

		printf( "%d\n", iVal );

		printf( "%d\n", (int)eVal );
	}
	#endif

	#ifdef __cplusplus
	/*
		bool <-> int
	*/
	{
		bool bVal = true;
		int iVal = bVal;
		int i2 = 5;
		bool b2 = i2;
		int i3 = b2;


		printf( "%d\n", iVal );
		printf( "%d\n", (int)b2 );
		printf( "%d\n", (int)i3 );
	}
	#endif

	/*
		unsigned short <-> signed int
	*/
	{
		unsigned short usVal = 0xFFFF;
		int iVal = usVal;

		printf( "%d\n", iVal );
	}

	/*
		signed short <-> unsigned int
	*/
	{
		short sVal = -1;
		unsigned uVal = sVal;

		printf( "%u %x\n", uVal, uVal );
	}

	/*
		float with int compare
	*/
	{
		double	flt = 1.5;
		int		i = 1;

		if( flt > i )
			printf( "%f > %d\n", flt, i );
		if( i < flt )
			printf( "%d < %f\n", i, flt );
	}

	/*
		long long with int compare
	*/
	{
		long long	i64 = 0x123456789LL;
		int			i32 = 0x23456789;

		if( i64 == i32 )
			printf( "%010lld == %010d\n", i64, i32 );
		else
			printf( "%010lld != %010d\n", i64, i32 );
	}

	#ifndef __cplusplus
	/*
		pointer conversions
	*/
	{
		struct tst1
		{
			int tst1;
		};
		struct tst2
		{
			int tst2;
		};

		void *vPtr = 0x123456;
		int *iPtr = vPtr;
		long *lPtr = iPtr;
		void *v2Ptr = lPtr;
		struct tst1 *s1Ptr = lPtr;
		struct tst2 *s2Ptr = s1Ptr;
		int i = iPtr;
		char *cPtr = i;

		printf( "%x\n", s2Ptr );
	}
	#endif

	#ifdef __cplusplus
	{
		class Integer
		{
			int	value;

			public:
			Integer( int i, int factor=1 ) : value(i*factor)
			{
			}

			operator int ( void )
			{
				return value;
			}
		};
		Integer	iVal = 5;
		int		i = iVal + 5;

		printf( "%d\n", i );
	}
	#endif
	{
		struct Integer
		{
			int value;
		}	iVal;

		int	i=5;
		int j;
		iVal = (struct Integer)i;
		j = (int)iVal;

		printf( "%d\n", j );
	}
	return 0;
}
