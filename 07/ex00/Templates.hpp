#ifndef _TEMPLATES_
	#define _TEMPLATES_


template < typename T>
void swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template < typename T>
T min(T x, T y)
{
	return (y <= x ? y : x);
}

template < typename T>
T max(T x, T y)
{
	return (y >= x ? y : x);
}

#endif