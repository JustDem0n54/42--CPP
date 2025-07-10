#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("default")
{
	std::cout << "Default Animal constructor." << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "Animal constructor." << std::endl;
}

AAnimal::AAnimal(AAnimal& copy)
{
	*this = copy;
	std::cout << "Copy Animal constructor." << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor." << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "... no sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->_type;
}