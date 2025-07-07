#ifndef _CLAPTRAP_
	#define _CLAPTRAP_

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int	_hit_points;
		int _energy_points;
		int _attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& copy);
		ClapTrap& operator=(ClapTrap& copy);
		virtual ~ClapTrap();

		std::string getName();
		int getAttackDamage();
		int getEnergyPoints();
		int getHitPoints();
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amout);
		void beRepaired(unsigned int amout);

};


#endif