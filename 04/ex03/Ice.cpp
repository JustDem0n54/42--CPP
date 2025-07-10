#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(Ice& copy): AMateria(copy)
{
}

Ice& Ice::operator=(Ice& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice();
	return(clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}