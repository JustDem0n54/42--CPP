#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}