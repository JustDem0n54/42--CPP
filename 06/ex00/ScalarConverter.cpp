#include "ScalarConverter.hpp"

bool check_str(std::string str)
{
	for (int i = 0; i < static_cast<int>(str.length() - 1); i++)
	{
		if (i == 0 && str[i] == '-')
			i++;
		if ((!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f') || (str[i] == 'f' && i < static_cast<int>(str.length() - 1)))
			return (false);
	}
	return (true);
}

bool check_inf(std::string str, int type)
{
	if (type == FLOAT && (str == "-inff" || str == "+inff" || str == "nanf"))
		return true;
	if (type == DOUBLE && (str == "-inf" || str == "+inf" || str == "nan"))
		return true;
	return false;
}


void convert_char(std::string str)
{
	std::stringstream convert(str);
	char c;
	convert.get(c);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convert_int(std::string str)
{
	std::stringstream convert(str);
	int i;
	convert >> i;
	if (i < 0 || i > 127)
		std::cout << "char: impossible " << std::endl;
	else if (std::isprint(i) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void float_inf(std::string str)
{
	char *endptr;
	float f = std::strtof(str.c_str(), &endptr);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convert_float(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		float_inf(str);
		return;
	}
	std::stringstream convert(str);
	float f;
	convert >> f;
	if (f < 0 || f > 127)
		std::cout << "char: impossible " << std::endl;
	else if (std::isprint(f) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void double_inf(std::string str)
{
	char *endptr;
	double d = std::strtod(str.c_str(), &endptr);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void convert_double(std::string str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		double_inf(str);
		return;
	}
	std::stringstream convert(str);
	double d;
	convert >> d;
	if (d < 0 || d > 127)
		std::cout << "char: impossible " << std::endl;
	else if (std::isprint(d) == 0)
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

int detect_type(std::string str)
{
	if (str.empty())
		return (ERROR);
	else if (str.length() == 1 && !std::isdigit(static_cast<char>(str[0])))
		return (CHAR);
	else if ((str.find('.') != std::string::npos && str.find('f', str.length() - 1) == std::string::npos && check_str(str) == true) || check_inf(str, DOUBLE) == true)
		return (DOUBLE);
	else if ((str.find('.') != std::string::npos && str.find('f', str.length() - 1) != std::string::npos && check_str(str) == true) || check_inf(str, FLOAT) == true)
		return (FLOAT);
	else if (check_str(str) == true)
		return (INT);
	else
		return (ERROR);
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
		convert_float(str);
		break;
	case DOUBLE:
		convert_double(str);
		break;
	case ERROR:
		std::cerr << "Invalid parameter." << std::endl;
		break;
	default:
		std::cout << "default" << std::endl;
		break;
	}
}