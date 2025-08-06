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

void RPN::ParsingEntry(std::string str) const
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
			throw std::invalid_argument("Error");
		else if ((str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '*') && str[i + 1] != ' ' && i != str.length() - 1)
			throw std::invalid_argument("Error");
		else if (isdigit(str[i]) == 0 && (str[i] != '/' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != ' '))
			throw std::invalid_argument("Error");
		else if ((str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '*') && operands < 2)
			throw std::invalid_argument("Error");
	}
	if (operands != operators + 1)
		throw std::invalid_argument("Error");
}

void RPN::Stock(int nb)
{
	this->_rpn.push(nb);
}

bool RPN::Operation(char c)
{
	int temp1 = this->_rpn.top();
	this->_rpn.pop();
	int temp2 = this->_rpn.top();
	this->_rpn.pop();
	switch(c)
	{
		case('/'):
			if (temp1 == 0)
				return std::cerr << "Cannot devide by 0." << std::endl, false;
			this->_rpn.push(temp2 / temp1);
			break;
		case('*'):
			this->_rpn.push(temp1 * temp2);
			break;
		case('-'):
			this->_rpn.push(temp2 - temp1);
			break;
		case('+'):
			this->_rpn.push(temp2 + temp1);
			break;
	}
	return true;
}

void RPN::ResolveRPN(std::string str)
{
	try
	{
		RPN::ParsingEntry(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) != 0)
			RPN::Stock(std::atoi(str.substr(i, i + 1).c_str()));
		else if (str[i] != ' ')
		{
			if (RPN::Operation(str[i]) == false)
				return ;
		}
	}
	std::cout << this->_rpn.top() << std::endl;
}
