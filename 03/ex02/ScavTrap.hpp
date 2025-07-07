#ifndef _SCAVTRAP_
	#define _SCAVTRAP_

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap& copy);
		ScavTrap& operator=(ScavTrap& copy);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif