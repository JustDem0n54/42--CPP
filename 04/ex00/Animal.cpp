#include "Animal.hpp"

Animal::Animal(): _type("default")
{
	std::cout << "Default Animal constructor." << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal constructor." << std::endl;
}

Animal::Animal(Animal& copy)
{
	*this = copy;
	std::cout << "Copy Animal constructor." << std::endl;
}

Animal& Animal::operator=(Animal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor." << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "... no sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}