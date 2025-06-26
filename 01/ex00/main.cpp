#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main()
{
	Zombie *test2;
	test2 = newZombie("ca marche");
	test2->announce();
	delete test2;

	randomChump("test");
	return 0;
}