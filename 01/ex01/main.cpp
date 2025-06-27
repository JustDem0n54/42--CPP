#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name);

int main()
{
	Zombie *test; 

	test = ZombieHorde(9, "Kevin");
	for (int i = 0; i < 9; i++)
	{
		test[i].announce();
	}
	delete[] test;
	return 0;
}