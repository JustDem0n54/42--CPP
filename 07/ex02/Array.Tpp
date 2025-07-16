#ifndef _ARRAY_TPP
	#define _ARRAY_TPP

#include <cstddef>
#include <stdexcept>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n)
{}

template <typename T>
Array<T>::Array(const Array& copy): _array(copy._array), _size(copy._size)
{}

template <typename T>
Array<T>::~Array()
{
	delete this->_array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{

}





#endif