#ifndef _MATERIASOURCE_
	#define _MATERIASOURCE_

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materia[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource& copy);
		MateriaSource& operator=(MateriaSource& copy);
		virtual ~MateriaSource();
		
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif