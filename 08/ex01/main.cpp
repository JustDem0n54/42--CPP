#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(time(0));
	Span sp = Span(10000);
	
	for (int i = 0; i < 10000; i++)
	{
		sp.addNumber(rand());
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "==============================" << std::endl;

	Span spa = Span(5);

	spa.addNumber(6);
	spa.addNumber(3);
	spa.addNumber(17);
	spa.addNumber(9);
	spa.addNumber(11);

	std::cout << spa.shortestSpan() << std::endl;
	std::cout << spa.longestSpan() << std::endl;
	return 0;
}
