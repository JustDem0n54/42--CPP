#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
	Zombie*	Hordes = new Zombie[N];
	
	for(int i = 0; i < N; i++)
	{
		Hordes[i].set_name(name);
	}
	return (Hordes);
}