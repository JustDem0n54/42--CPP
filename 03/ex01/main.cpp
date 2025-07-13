#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("clap");
	std::cout << "==========================" << std::endl;
    ScavTrap Scav("Scav");
	std::cout << "==========================" << std::endl;

	clap.attack("ennemy");
	std::cout << "==========================" << std::endl;
	Scav.attack("ennemy");
	Scav.guardGate();
	std::cout << "==========================" << std::endl;
}

