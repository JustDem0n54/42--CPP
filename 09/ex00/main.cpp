#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>
#include <sstream>
#include <cstdlib>
#include <iterator>

bool valid_date(std::string date)
{
	if (date.size() != 10)
		return std::cout << "false1" << std::endl, false;
	if (date[4] != '-' || date[7] != '-')
		return std::cout << "false2" << std::endl, false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			i++;
		else if (!isdigit(date[i]))
			return std::cout << "false3" << std::endl, false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Need only 1 argument. Exemple : input.txt" << std::endl, 1);
	(void)argv;
	std::map<std::string, float> data;
	std::string line;
	std::ifstream btc("data.csv");
	std::getline(btc, line);
	while (std::getline(btc, line))
	{
		size_t sep = line.find(',');
		if (sep != std::string::npos)
		{
			std::string date = line.substr(0, sep);
			if (valid_date(date) == false)
				return 1;
			std::string value_str = line.substr(sep + 1);

			float value = static_cast<float>(atof(value_str.c_str()));
			data[date] = value;
		}
		else
			return (std::cerr << "Invalid caracters in data file" << std::endl, 1);
	}

	for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
	{
		std::cout << it->first << ", " << it->second << std::endl;
	}
	return (0);
}