#ifndef _ANIMAL_
	#define _ANIMAL_

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal& copy);
		Animal& operator=(Animal& copy);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif