#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return std::cerr << "Error" << std::endl, 1;
	std::string entry = argv[1];
	RPN resolve;
	resolve.RPN::ResolveRPN(entry);
	return 0;
}