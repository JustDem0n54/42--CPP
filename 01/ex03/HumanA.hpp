#ifndef _HUMANA_
	#define _HUMANA_

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private: 
		std::string _name;
		Weapon& _weapon;
	public:
		HumanA(const std::string& name, Weapon& new_weapon);
		~HumanA();
		void attack();
};

#endif