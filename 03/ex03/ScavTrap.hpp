#ifndef _SCAVTRAP_
	#define _SCAVTRAP_

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		int _default_energy_point;
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