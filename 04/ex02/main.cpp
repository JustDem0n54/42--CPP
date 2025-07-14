#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	int n = 3;
	AAnimal *tab[n * 2];
	// AAnimal test("Cat");

	for (int i = 0; i < n; i++)
	{
		tab[i] = new Dog();
	}

	for (int i = n; i < n*2; i++)
	{
		tab[i] = new Cat();
	}

	for (int i = 0; i < n*2; i++)
	{
		delete tab[i];
	}
	
	return 0;
}