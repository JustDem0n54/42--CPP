#include "Zombie.hpp"

Zombie::Zombie()
{

}
Zombie::Zombie(std::string name): _name(name)
{

}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}