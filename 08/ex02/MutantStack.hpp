#ifndef _MUTANTSTACK_HPP
	#define _MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <cstddef>
#include <deque>

template < typename T >
class MutantStack: public std::stack<T>
{
	private:
	public:
		typedef typename std::deque<T>::iterator iterator;
		
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}

		void push(T value);
		T top() const;
		void pop();
		size_t size() const;
		bool empty() const;
};

#include "MutantStack.tpp"

#endif