#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "====MUTANTSTACK TEST=====" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	std::cout << "=========================" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "====LIST TEST============" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;

	list.pop_back();
	std::cout << list.size() << std::endl;

	std::cout << "=========================" << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator itlist = list.begin();
	std::list<int>::iterator itelist = list.end();

	++itlist;
	--itlist;
	while (itlist != itelist)
	{
		std::cout << *itlist << std::endl;
		++itlist;
	}

	std::cout << "====COPY TEST============" << std::endl;
	MutantStack<int> copy(mstack);

	MutantStack<int>::iterator itcopy = copy.begin();
	MutantStack<int>::iterator itecopy = copy.end();

	++itcopy;
	--itcopy;
	while (itcopy != itecopy)
	{
		std::cout << *itcopy << std::endl;
		++itcopy;
	}

	std::cout << "====OPERATOR COPY TEST============" << std::endl;
	MutantStack<int> OPcopy;

	OPcopy = copy;
	MutantStack<int>::iterator itOPcopy = copy.begin();
	MutantStack<int>::iterator iteOPcopy = copy.end();

	++itOPcopy;
	--itOPcopy;
	while (itOPcopy != iteOPcopy)
	{
		std::cout << *itOPcopy << std::endl;
		++itOPcopy;
	}

	std::cout << "====STACK FROM MUTANT============" << std::endl;
	std::stack<int> s(OPcopy);

	for (int i = 0; i < 5; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return 0;
}