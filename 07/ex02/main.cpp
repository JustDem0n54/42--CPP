#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	std::cout << "===============================================" << std::endl;
	Array<int> empty;
	for (unsigned int i = 0; i < empty.size(); i++)
    {
		std::cout << empty[i] << std::endl;
    }
	Array<char> string(8);
	char str[] = "Bonjour";
	for (int i = 0; i < 8; i++)
    {
        string[i] = str[i];
		std::cout << string[i] << std::endl;
    }
	Array<char> copy(string);
	for (int i = 0; i < 8; i++)
    {
		std::cout << copy[i] << std::endl;
    }

    delete [] mirror;//
    return 0;
}