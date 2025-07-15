#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generate()
{
	int random = std::rand() % 3;
	if (random == 0)
		return new A();
	if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;		
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(...){}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(...){}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(...){}
}

int main()
{
	std::srand(time(0));
	Base* test = generate();
	Base* test2 = generate();
	Base* test3 = generate();
	
	identify(test);
	identify(test);
	std::cout << "=====================================" << std::endl;
	identify(test2);
	identify(test2);
	std::cout << "=====================================" << std::endl;
	identify(test3);
	identify(test3);
}