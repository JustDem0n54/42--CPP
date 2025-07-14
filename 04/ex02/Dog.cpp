#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "Default Dog constructor." << std::endl;
}

Dog::Dog(Dog& copy): AAnimal(copy)
{
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
	std::cout << "Copy Dog constructor." << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor." << std::endl;
}

Dog& Dog::operator=(Dog& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Waf Waaaf !" << std::endl;
}