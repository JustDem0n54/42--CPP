#ifndef _AANIMAL_
	#define _AANIMAL_

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal& copy);
		AAnimal& operator=(AAnimal& copy);
		virtual ~AAnimal();
		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif