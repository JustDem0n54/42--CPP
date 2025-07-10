#ifndef _ICE_
	#define _ICE_

#include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		std::string const& getType() const;
		AMateria* clone() const = 0;
		void use(ICharacter& target);
};

#endif