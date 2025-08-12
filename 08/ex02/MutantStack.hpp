#ifndef _MUTANTSTACK_
	#define _MUTANTSTACK_

#include <stack>
#include <iterator>
#include <cstddef>
#include <deque>

template < typename T >
class MutantStack: public std::stack<T>
{
	private:
	public:
		MutantStack() {}
		MutantStack(const MutantStack& copy) {*this = copy;}
		MutantStack& operator=(const MutantStack& copy)
		{
			if (this != &copy)
				std::stack<T>::operator=(copy);
			return *this;	
		}
		~MutantStack() {}
		
		typedef typename std::deque<T>::iterator iterator;
		
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};

#endif