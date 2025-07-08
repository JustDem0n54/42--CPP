#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default construtor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->_hit_points = FragTrap::_default_hit_point;
	this->_energy_points = ScavTrap::_default_energy_point;
	this->_attack_damage = FragTrap::_default_attack_damage;
	std::cout << "DiamondTrap " + this->_name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	this->_attack_damage = copy.getAttackDamage();
	this->_energy_points = copy.getEnergyPoints();
	this->_hit_points = copy.getHitPoints();
	std::cout << "DiamondTrap " + this->_name << " has been copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& copy)
{
	if (this != &copy)
	{
		this->_attack_damage = copy.getAttackDamage();
		this->_energy_points = copy.getEnergyPoints();
		this->_hit_points = copy.getHitPoints();
		this->_name = copy.getName();
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DianondTrap " + this->_name << " has been destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "His name is " + this->_name 
	+ ". His Clapname is " + this->getName() << std::endl;
}
