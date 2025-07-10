#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hit_points(0), _energy_points(0), _attack_damage(0)
{
	std::cout << "ClapTrap Default construtor" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << this->_name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& copy)
{
	*this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap& copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_attack_damage = copy.getAttackDamage();
		this->_hit_points = copy.getHitPoints();
		this->_energy_points = copy.getEnergyPoints();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

std::string ClapTrap::getName()
{
	return this->_name;
}

int ClapTrap::getAttackDamage()
{
	return this->_attack_damage;
}

int ClapTrap::getEnergyPoints()
{
	return this->_energy_points;
}

int ClapTrap::getHitPoints()
{
	return this->_hit_points;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " + _name + " attacks " + target + " causing " << this->_attack_damage << " point of damage" << std::endl;
	}
	else if (this->_energy_points == 0)
		std::cout << "ClapTrap " + _name + " doesn't have enought EP" << std::endl;
	else if (this->_hit_points == 0)
		std::cout << "ClapTrap " + _name + " doesn't have enought HP" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ClapTrap " + this->_name + " is already dead.";
		return ;
	}
	this->_hit_points -= amount;
	std::cout << "ClapTrap " + _name + " lost " << amount << " HP" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_hit_points += amount;
		this->_energy_points--;
		std::cout << "ClapTrap " + _name + " has regained " << amount << " HP" << std::endl;
	}
	else if (this->_energy_points <= 0)
		std::cout << "ClapTrap " + _name + " doesn't have enought EP" << std::endl;
	else if (this->_hit_points <= 0)
		std::cout << "ClapTrap " + _name + " doesn't have enought HP" << std::endl;
}
