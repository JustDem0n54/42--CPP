#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap Default construtor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_attack_damage = 30;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_default_attack_damage = this->_attack_damage;
	this->_default_hit_point = this->_hit_points;
	std::cout << "FragTrap " + this->_name << " has been created." << std::endl;
}

FragTrap::FragTrap(FragTrap& copy): ClapTrap(copy)
{
	this->_attack_damage = copy.getAttackDamage();
	this->_energy_points = copy.getEnergyPoints();
	this->_hit_points = copy.getHitPoints();
	this->_default_attack_damage = this->_attack_damage;
	this->_default_hit_point = this->_hit_points;
	std::cout << "FragTrap " + this->_name << " has been copied." << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& copy)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " + this->_name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Hey bro ! High-fives !" << std::endl;
}
