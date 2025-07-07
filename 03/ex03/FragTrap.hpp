#ifndef _FRAGTRAP_
	#define _FRAGTRAP_

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		int _default_hit_point;
		int _default_attack_damage;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap& copy);
		FragTrap& operator=(FragTrap& copy);
		~FragTrap();
		void highFivesGuys();
};


#endif