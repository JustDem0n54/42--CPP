#ifndef _SCALARCONVERTER_
	#define _SCALARCONVERTER_

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();
	public:
		static void convert(std::string str);
};

#endif