#ifndef _FRAGTRAP_
	#define _FRAGTRAP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap& copy);
	FragTrap& operator=(FragTrap& copy);
	~FragTrap();
	void highFivesGuys();
};


#endif