#ifndef _EASYFIND_
	#define _EASYFIND_

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

template < typename T >
typename T::iterator easyfind(T container, int search)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), search);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return it;
		
}

#endif