#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);

	try
	{
		easyfind(v, 3);
		easyfind(v, 8);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		easyfind(l, 20);
		easyfind(l, 90);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}

