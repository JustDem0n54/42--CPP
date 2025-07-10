#ifndef _ICHARACTER_
	#define _ICHARACTER_

#include <string>
#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
	private:
		std::string _name;
		AMateria* inventory;
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif