#ifndef _BITCOINEXCHANGE_
	#define _BITCOINEXCHANGE_

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <utility>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& copy);

		int StockDataInMap(std::string file);
		bool IsValidDate(std::string date) const;
		std::string FindValidDate(std::string date);
		float FindValidValue(std::string input);
		float ExchangeValue(std::string date, float value);
};

#endif