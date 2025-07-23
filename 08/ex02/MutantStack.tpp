#ifndef _MUTANTSTACK_TPP
	#define _MUTANTSTACK_TPP

template <typename T>
void MutantStack<T>::push(T value)
{
	std::stack<T>::push(value);
}

template <typename T>
T MutantStack<T>::top() const
{
	return std::stack<T>::top();
}

template <typename T>
void MutantStack<T>::pop()
{
	std::stack<T>::pop();
}

template <typename T>
bool MutantStack<T>::empty() const
{
	return std::stack<T>::empty();
}

template <typename T>
size_t MutantStack<T>::size() const
{
	return std::stack<T>::size();
}

#include "MutantStack.hpp"

#endif