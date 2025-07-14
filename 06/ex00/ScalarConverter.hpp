#ifndef _SCALARCONVERTER_
	#define _SCALARCONVERTER_

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <iomanip>

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
	public:
		static void convert(std::string str);
};

#endif