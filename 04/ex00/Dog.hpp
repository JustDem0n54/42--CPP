#ifndef _DOG_
	#define _DOG_

#include "Animal.hpp"

class Dog : public Animal
{
	private:

	public:
		Dog();
		Dog(Dog& copy);
		Dog& operator=(Dog& copy);
		~Dog();
		void makeSound() const;
};

#endif 