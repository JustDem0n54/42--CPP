#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::Cure(Cure& copy): AMateria(copy)
{
}

Cure& Cure::operator=(Cure& copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure();
	return(clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
}

