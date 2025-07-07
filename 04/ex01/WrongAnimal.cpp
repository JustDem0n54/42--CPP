#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("default")
{
	std::cout << "Default WrongAnimal constructor." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout << "WrongAnimal constructor." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	*this = copy;
	std::cout << "Copy WrongAnimal constructor." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor." << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}