#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "Default Cat constructor." << std::endl;
}

Cat::Cat(Cat& copy): Animal(copy)
{
	this->_type = copy._type;
	std::cout << "Copy Cat constructor." << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor." << std::endl;
}

Cat& Cat::operator=(Cat& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouuuuuu !" << std::endl;
}