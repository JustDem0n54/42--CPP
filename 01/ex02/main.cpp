#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "memory adress of str :" << &str << std::endl;
	std::cout << "memory adress of stringPTR :" << stringPTR << std::endl;
	std::cout << "memory adress of stringREF :" << &stringREF << std::endl;
	std::cout << "\n";
	std::cout << "value of str:" << str << std::endl;
	std::cout << "value of stringPTR:" << *stringPTR << std::endl;
	std::cout << "value of stringREF:" << stringREF << std::endl;
}