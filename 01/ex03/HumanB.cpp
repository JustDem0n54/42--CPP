#include "HumanB.hpp"	
	
HumanB::HumanB(const std::string& name): _name(name), _weapon(NULL)
{
}

void HumanB::setWeapon(Weapon& NewWeapon)
{
	this->_weapon = &NewWeapon;
}

void HumanB::attack() const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}