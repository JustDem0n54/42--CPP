#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	std::string inputfile = argv[1];
	std::ifstream in(inputfile.c_str());
	if (!in)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	BitcoinExchange data;
	if (data.StockDataInMap("data.csv") == 1)
		return 1;
	std::string input;
	std::getline(in, input);
	if (input.compare("date | value") != 0)
		return std::cerr << "Error: bad input => " << input << std::endl, 1;
	while (std::getline(in, input))
	{
		size_t sep = input.find('|');
		if (sep != std::string::npos)
		{
			std::string date = input.substr(0, sep - 1);
			if (data.IsValidDate(date))
			{
				date = data.FindValidDate(date);
				float value = data.FindValidValue(input.substr(sep + 2));
				if (!date.empty() && value >= 0)
					std::cout << input.substr(0, sep - 1) << " => " << value << " = " << data.ExchangeValue(date, value) << std::endl;
			}
		}
		else 
			std::cerr << "Error: bad input => " << input << std::endl;
	}
	return (0);
}
