#ifndef ARRAY_HPP
	#define ARRAY_HPP

#include <cstddef>

template < typename T >
class Array
{
	private:
		T* _array;
		size_t _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		~Array();

};

#include "Array.Tpp"

#endif