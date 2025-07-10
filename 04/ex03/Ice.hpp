#ifndef _ICE_
	#define _ICE_

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice();

		Ice(Ice& copy);
		Ice& operator=(Ice& copy);
		~Ice();
		std::string const& getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif