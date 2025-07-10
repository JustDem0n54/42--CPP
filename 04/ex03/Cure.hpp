#ifndef _CURE_
	#define _CURE_

#include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure();

		Cure(Cure& copy);
		Cure& operator=(Cure& copy);
		~Cure();
		std::string const& getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};


#endif