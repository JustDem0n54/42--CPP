#include "HumanA.hpp"	

HumanA::HumanA(const std::string& name, Weapon& new_weapon): _name(name), _weapon(new_weapon)
{
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}