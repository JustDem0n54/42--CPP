#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* Wrongmeta = new WrongAnimal();
	const WrongAnimal* Wrongi = new WrongCat();
	Wrongmeta->makeSound();
	Wrongi->makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}