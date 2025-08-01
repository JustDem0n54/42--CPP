#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		this->_data = copy._data;
	return *this;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::IsValidDate(std::string date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return std::cerr << "Error: bad input => " << date << std::endl, false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			i++;
		else if (!isdigit(date[i]))
			return std::cerr << "Error: bad input => " << date << std::endl, false;
	}
	int day = atoi((date.substr(8, 10)).c_str());
	int month = atoi((date.substr(5, 7)).c_str());
	int years = atoi((date.substr(0, 4)).c_str());
	int dayInMounth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(years))
		dayInMounth[1] = 29;
	if (month > 12 || day > dayInMounth[month - 1])
		return std::cerr << "Error: bad input => " << date << std::endl, false;
	return true;
}

void BitcoinExchange::StockDataInMap(std::string file)
{
	std::string line;
	std::ifstream btc(file.c_str());
	std::getline(btc, line);
	while (std::getline(btc, line))
	{
		size_t sep = line.find(',');
		if (sep != std::string::npos)
		{
			std::string date = line.substr(0, sep);
			if (BitcoinExchange::IsValidDate(date) == false)
				return ;
			std::string value_str = line.substr(sep + 1);

			float value = static_cast<float>(atof(value_str.c_str()));
			this->_data[date] = value;
		}
		else
		{
			std::cerr << "Invalid caracters in data file" << std::endl;
			return ;
		}	
	}
}

std::string BitcoinExchange::FindValidDate(std::string date)
{
	std::map<std::string, float>::iterator it = _data.begin();
	for (it = _data.begin(); it != _data.end(); it++)
	{
		if (it->first.compare(date) > 0 && it == _data.begin())
			return std::cout << "Error: bad input => " + date << std::endl, "";
		else if (it->first.compare(date) > 0 && it != _data.begin())
		{
			it--;
			return it->first;
		}
		else if (it->first.compare(date) == 0)
			return it->first;
	}
	if (it == _data.end())
	{
		it--;
		return it->first;
	}
	else
		return "";
}

float BitcoinExchange::FindValidValue(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && input[i] == '-')
			i++;
		if (isdigit(input[i]) == 0 && input[i] != '.')
			return std::cout << "Error: bad input -> " + input << std::endl, -1.0f;
	}
	float value = atof(input.c_str());
	if (value > 1000)
		return std::cout << "Error: too large a number." << std::endl, -1.0f;
	if (value < 0)
		return std::cout << "Error: not a positive number." << std::endl, -1.0f;
	return value;
}

float BitcoinExchange::ExchangeValue(std::string date, float value)
{
	return this->_data[date] * value;
}
