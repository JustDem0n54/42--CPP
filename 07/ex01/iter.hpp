#ifndef _ITER_
	#define _ITER_

template <typename T>
void iter(T* address, unsigned int lenght, void (*f)(const T&))
{
	for (unsigned int i = 0; i < lenght; i++)
		f(address[i]);
}

template <typename T>
void iter(T* adress, unsigned int lenght, void (*f)(T&))
{
	for (unsigned int i = 0; i < lenght; i++)
		f(adress[i]);
}

#endif