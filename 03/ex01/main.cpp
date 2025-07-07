#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("clap");
    ScavTrap Scav("Scav");

	clap.attack("ennemy");
	Scav.attack("ennemy");
	Scav.guardGate();
}
