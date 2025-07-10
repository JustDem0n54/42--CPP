#ifndef _CHARACTER_
	#define _CHARACTER_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	protected:
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(Character& copy);
		Character& operator=(Character& copy);
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif