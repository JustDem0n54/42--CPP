#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_points = 100;
	this->_attack_damage = 20;
	this->_energy_points = 50;
	std::cout << "ScavTrap " + this->_name << " has been created." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " + this->_name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ScavTrap " + _name + " attacks " + target + " causing " << this->_attack_damage << " point of damage" << std::endl;
	}
	else if (this->_energy_points == 0)
		std::cout << "ScavTrap " + _name + " doesn't have enought EP" << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "ScavTrap " + _name + " doesn't have enought HP" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " + _name + " is now in Gate keeper mode" << std::endl;
}