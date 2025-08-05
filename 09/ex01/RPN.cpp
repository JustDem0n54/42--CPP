#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		this->_rpn = copy._rpn;
	return *this;
}

RPN::~RPN()
{}

bool RPN::ParsingEntry(std::string str) const
{
	int operands = 0;
	int operators = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) != 0)
			operands++;
		if (str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '*')
			operators++;
		if (isdigit(str[i]) != 0 && str[i + 1] != ' ')
			return std::cerr << "Error1" << std::endl, false;
		else if ((str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '*') && str[i + 1] != ' ' && i != str.length() - 1)
			return std::cerr << "Error2" << std::endl, false;
		else if (isdigit(str[i]) == 0 && (str[i] != '/' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != ' '))
			return std::cerr << "Error13" << std::endl, false;
		else if ((str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '*') && operands < 2)
			return std::cerr << "Error14" << std::endl, false;
	}
	if (operands != operators + 1)
		return false;
	return true;
}
