#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap mega("diamond");
	std::cout << "hit points: " << mega.getHitPoints() 
	<< " attack : " << mega.getAttackDamage() 
	<< " energy points : " << mega.getEnergyPoints() << std::endl;
	mega.attack("Enemy1");
	mega.whoAmI();
    return 0;
}
