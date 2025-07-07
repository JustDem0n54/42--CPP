#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("clap");
    ScavTrap Scav("Scav");
	FragTrap frag("frag");

	clap.attack("ennemy");
	Scav.attack("ennemy");
	Scav.guardGate();
	frag.attack("ennemy");
	frag.highFivesGuys();
}
