#ifndef _AMATERIA_
	#define _AMATERIA_

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(AMateria& copy);
		AMateria& operator=(AMateria& copy);
		virtual ~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif