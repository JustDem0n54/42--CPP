#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(time(0));
	Span sp = Span(10000);

	int arr[10000];
	for (int i = 0; i < 10000; i++)
		arr[i] = rand();

	try 
	{
		sp.addNumbers(arr, 10000);
		std::vector<int> tab = sp.getTab();
		std::cout << tab[0] << " " << tab[1] << " " << tab[2] << std::endl;
		std::cout << tab[tab.size() - 3] << " " << tab[tab.size() - 2] << " " << tab[tab.size() - 1] << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "==============================" << std::endl;

	Span spa = Span(5);

	try
	{
		spa.addNumber(6);
		spa.addNumber(3);
		spa.addNumber(17);
		spa.addNumber(9);
		spa.addNumber(11);

		std::cout << spa.shortestSpan() << std::endl;
		std::cout << spa.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
