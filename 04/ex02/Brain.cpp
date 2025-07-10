#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "default";
	std::cout << "Default constructor Brain" << std::endl;
}

Brain::Brain(Brain& copy)
{
	*this = copy;
	std::cout << "Copy constructor Brain" << std::endl;
}

Brain& Brain::operator=(Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain" << std::endl;
}

