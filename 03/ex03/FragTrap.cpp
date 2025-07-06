#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_attack_damage = 30;
	this->_hit_points = 100;
	this->_energy_points = 100;
	std::cout << "FragTrap " + this->_name << " has been created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " + this->_name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Hey bro ! High-fives !" << std::endl;
}
