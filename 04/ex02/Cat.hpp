#ifndef _CAT_
	#define _CAT_

#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat : public AAnimal
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