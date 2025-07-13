#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap mega("diamond");
	std::cout << "==========================" << std::endl;
	std::cout << "hit points: " << mega.getHitPoints() 
	<< " attack : " << mega.getAttackDamage() 
	<< " energy points : " << mega.getEnergyPoints() << std::endl;
	std::cout << "==========================" << std::endl;
	mega.attack("Enemy1");
	mega.whoAmI();
	mega.highFivesGuys();
	mega.guardGate();
	std::cout << "==========================" << std::endl;
    return 0;
}
