#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		return std::cerr << "Error" << std::endl, 1;
	PmergeMe mergeme;
	mergeme.FordJonhson(argv, argc);
	return 0;
}