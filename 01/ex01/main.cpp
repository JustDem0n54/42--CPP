#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name);

int main()
{
	Zombie *test2; 

	test2 = ZombieHorde(9, "Kevin");
	for (int i = 0; i < 9; i++)
	{
		test2[i].announce();
	}
	delete[] test2;
	return 0;
}