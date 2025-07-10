#ifndef _WRONGANIMAL_
	#define _WRONGANIMAL_

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal& copy);
		WrongAnimal& operator=(WrongAnimal& copy);
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};

#endif