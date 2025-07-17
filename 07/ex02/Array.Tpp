#ifndef _ARRAY_TPP
	#define _ARRAY_TPP

#include <cstddef>
#include <stdexcept>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(0), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(const Array& copy)
{
	_size = copy._size;
	this->_array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		if (this->_array)
			delete [] this->_array;
		this->_array = new T[copy._size]();
		for (unsigned int i = 0; i < copy._size; i++)
			this->_array[i] = copy._array[i];
		this->_size = copy._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template <typename T>
size_t Array<T>::size() const
{
	return this->_size;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= this->size())
		throw Array<T>::IndexOutOfBounds();
	return this->_array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= this->size())
		throw Array<T>::IndexOutOfBounds();
	return this->_array[index];
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const throw()
{
	return "Index is out of bounds.";
}

#endif