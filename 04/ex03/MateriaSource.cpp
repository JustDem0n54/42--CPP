#include "MateriaSoure.hpp"

MateriaSource::MateriaSource(): IMateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = 0;
	}
}


MateriaSource::MateriaSource(MateriaSource& copy)
{
	for (int i = 0; i < 4; i++)
	{
		delete _materia[i];
		this->_materia[i] = copy._materia[i];
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_materia[i];
			this->_materia[i] = copy._materia[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;

	if (!m)
		return ;
	while (this->_materia[i] != 0)
		i++;
	if (i >= 4)
		std::cout << "Stock of materia is full." << std::endl;
	else
		this->_materia[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	std::cout << "No matching type" << std::endl;
	return 0;
}