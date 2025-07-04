#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{	
			(this->*function[i])();
			return ;
		}
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
