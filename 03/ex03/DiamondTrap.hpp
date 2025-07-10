#ifndef _DIAMONDTRAP_
	#define _DIAMONDTRAP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap& copy);
		DiamondTrap& operator=(DiamondTrap& copy);
		~DiamondTrap();
		void whoAmI();
};

#endif