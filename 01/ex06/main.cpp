#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		return (std::cout << "Need a level of security." << std::endl, 1);
	harl.complain(argv[1]);
	return 0;
}