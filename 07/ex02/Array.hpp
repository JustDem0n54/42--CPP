#ifndef ARRAY_HPP
	#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <string>

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
		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		size_t size() const;


	class IndexOutOfBounds : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#include "Array.Tpp"

#endif