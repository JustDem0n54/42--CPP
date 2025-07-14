#include "ScalarConverter.hpp"

bool check_str(std::string str)
{
	for (int i = 0; i < static_cast<int>(str.length() - 1); i++)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && (str[i] == 'f' && i < static_cast<int>(str.length() - 1)))
			return (false);
	}
	return (true);
}

int detect_type(std::string str)
{
	if (str.length() == 1 && !std::isdigit(static_cast<char>(str[0])))
		return (CHAR);
	else if (str.find('.') != std::string::npos && str.find('f', str.length() - 1) == std::string::npos
		&& check_str(str) == true)
		return (DOUBLE);
	else if (str.find('.') != std::string::npos && str.find('f', str.length() - 1) != std::string::npos
		&& check_str(str) == true)
		return (FLOAT);
	else if (check_str(str) == true)
		return (INT);
	else
		return (ERROR);
}


void convert_char(std::string str)
{
	std::stringstream convert(str);
	char c;
	convert >> c;
	std::cout << c << std::endl;
	std::cout << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << static_cast<double>(c) << std::endl;
}

void convert_int(std::string str)
{
	std::stringstream convert(str);
	int i;
	convert >> i;
	if (i >= 13 && i <= 127)
		std::cout << static_cast<char>(i) << std::endl;
	else
		std::cout << "Nan displayeble" << std::endl;
	std::cout << (i) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	switch (detect_type(str))
	{
		case CHAR:
			convert_char(str);
			break;
		case INT:
			convert_int(str);
			break;
		case FLOAT:
			std::cout << FLOAT << std::endl;
			break;
		case DOUBLE:
			std::cout << DOUBLE << std::endl;
			break;
		case ERROR:
			std::cout << ERROR << std::endl;
			break;
		default:
			std::cout << "default" << std::endl;
			break;
	}
}