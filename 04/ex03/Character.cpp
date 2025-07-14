#include "Character.hpp"

Character::Character(): ICharacter()
{
	this->_name = "default";
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
}

Character::Character(std::string name): ICharacter()
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
}

Character::Character(Character& copy): _name(copy.getName())
{
	*this = copy;
}

Character& Character::operator=(Character& copy)
{
	if (this != &copy)
	{
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
	}
}

std::string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
		return ;
	while (this->_inventory[i] != 0)
		i++;
	if (i >= 4)
	{
		std::cout << "Invetory of Character " + this->_name + " is full." << std::endl;
		delete m;
	}
	else
		this->_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx > 3 || this->_inventory[idx] == 0 || idx < 0)
		std::cout << "This emplacement of the invetory is empty or does not exist." << std::endl;
	else 
		this->_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || this->_inventory[idx] == 0 || idx < 0)
		std::cout << "This Materia can not be used" << std::endl;
	else
		_inventory[idx]->use(target);
}
