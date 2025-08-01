#ifndef _CAT_
	#define _CAT_

#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(Cat& copy);
		Cat& operator=(Cat& copy);
		~Cat();
		void makeSound() const;
};

#endif 