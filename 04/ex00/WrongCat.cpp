#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "Default WrongCat constructor." << std::endl;
}

WrongCat::WrongCat(WrongCat& copy): WrongAnimal(copy)
{
	this->_type = copy._type;
	std::cout << "Copy WrongCat constructor." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor." << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& copy)
{
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}
