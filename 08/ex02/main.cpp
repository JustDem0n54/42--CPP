#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=========================" << std::endl;
	std::cout << "====MUTANTSTACK TEST=====" << std::endl;
	std::cout << "=========================" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	std::cout << "=========================" << std::endl;

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
	std::stack<int> s(mstack);
	std::cout << "=========================" << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;





	std::cout << "=========================" << std::endl;
	std::cout << "====LIST TEST============" << std::endl;
	std::cout << "=========================" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	std::cout << "=========================" << std::endl;

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
	return 0;
}