#ifndef _DOG_
	#define _DOG_

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(Dog& copy);
		Dog& operator=(Dog& copy);
		~Dog();
		void makeSound() const;
};

#endif 