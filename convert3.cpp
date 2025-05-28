// convert3.cpp
#include <iostream>

class Integer
{
	int	value;

	public:
	Integer( int i ) : value(i)
	{
	}

	int getValue() const
	{
		return value;
	}
};

class SuperInt : public Integer
{
	int	factor;

	public:
	SuperInt( int i, int f ) : Integer(i), factor(f)
	{
	}

	long getValue() const
	{
		return long(Integer::getValue()) * factor;
	}
};

class Long
{
	long	value;

	public:
	Long( long i ) : value(i)
	{
	}
	long getValue() const
	{
		return value;
	}
};

int main( void )
{
	{
		Integer		i(123);
		SuperInt	si(123,456);
		Integer		*ip = &si;
		//SuperInt	*sip = ip;					verboten
		SuperInt	*sip = static_cast<SuperInt *>(ip);

		// Long	*l = static_cast<Long *>(&i);	verboten

		std::cout << sip->getValue() << std::endl;
	}

	{
		int		i = 123;
		int		*ip = &i;
		//long	*lp = ip;						verboten
		//long	*lp = static_cast<long*>(ip);	verboten

		void	*vp = ip;
		// int	*ip2 = vp;						verboten
		int		*ip2 = static_cast<int*>(vp);

		std::cout << *ip2 << std::endl;
	}
	{
		Integer		i(123);
		SuperInt	si(123,456);

		//Long	l = reinterpret_cast<Long>(i);				// verboten

		short		s0 = 123;
		short		s1 = 456;
		short		s2 = 789;

		//long		l1 = reinterpret_cast<long>(s1);		// verboten
		long		*lp = reinterpret_cast<long*>(&s1);
		long		l2 = reinterpret_cast<long>(&s1);
		SuperInt	*sp = reinterpret_cast<SuperInt	*>(l2);

		// short	s = reinterpret_cast<short>(&s1);		// verboten
		short		s = 123;
		long		*lp2 = reinterpret_cast<long*>(s);

		std::cout << s0 << ' ' << *lp << ' ' << s2 << std::endl;
	}
	{
		Integer		i(123);

		Integer		&ir = i;
		Long		&lr = reinterpret_cast<Long&>( ir );

		std::cout << lr.getValue() << std::endl;	// undefiniertes verhalten
	}
	return 0;
}