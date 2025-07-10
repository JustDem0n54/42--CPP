#include "AMateria.hpp"

AMateria::AMateria(): _type("default")
{}

AMateria::AMateria(std::string const& type): _type(type)
{}

AMateria::AMateria(AMateria& copy)
{
	*this = copy;
}

AMateria& AMateria::operator=(AMateria& copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
	}
	return *this;
}

AMateria::~AMateria()
{}

std::string const& AMateria::getType() const
{
	return this->_type;
}

void 	AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "..." << std::endl;
}