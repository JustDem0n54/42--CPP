#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

int Harl::getIndex(const std::string& level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)	
			return (i + 1);
	}
	return (0);
}

void Harl::complain(std::string level)
{
	int index = getIndex(level);

	switch (index)
	{
	case 1:
		debug(); info(); warning(); error();
		break;
	case 2:
		info(); warning(); error();
		break;
	case 3:
		warning(); error();
		break;
	case 4:
		error();
		break;
	default:
		std::cout << "Level of security incorrect" << std::endl;
		break;
	}
}
		
void Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now." << std::endl;
}
