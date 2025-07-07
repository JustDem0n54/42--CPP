#ifndef _CAT_
	#define _CAT_

#include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		Cat(Cat& copy);
		Cat& operator=(Cat& copy);
		~Cat();
		void makeSound() const;
};

#endif 