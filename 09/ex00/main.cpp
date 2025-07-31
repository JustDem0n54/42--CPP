#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Need only 1 argument. Exemple : input.txt" << std::endl, 1);
	BitcoinExchange data;
	data.StockDataInMap("data.csv");

	std::string inputfile = argv[1];
	std::ifstream in(inputfile.c_str());
	std::string input;
	std::getline(in, input);
	while (std::getline(in, input))
	{
		size_t sep = input.find('|');
		if (sep != std::string::npos)
		{
			std::string date = input.substr(0, sep - 1);
			if (data.IsValidDate(date))
			{
				date = data.FindValidDate(date);
				float value = data.FindValidValue(input.substr(sep + 1));
				if (!date.empty() && value >= 0)
				{
					std::cout << input.substr(0, sep - 1) << " => " << value << " = " << data.ExchangeValue(date, value) << std::endl;
				}
			}
		}
		else 
			std::cerr << "Error: bad input => " << input << std::endl;
	}
	return (0);
}
