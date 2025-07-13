#include "ClapTrap.hpp"

int main()
{
    ClapTrap test("test");

    test.attack("mechant");
    test.attack("mechant");
    test.attack("mechant");
    test.attack("mechant");
    test.attack("mechant");
    test.attack("mechant");
    test.attack("mechant");
	test.takeDamage(5);
	std::cout << test.getHitPoints() << std::endl;
    test.beRepaired(20);
	std::cout << test.getHitPoints() << std::endl;
	test.beRepaired(20);
	std::cout << test.getHitPoints() << std::endl;
	test.beRepaired(20);
	std::cout << test.getHitPoints() << std::endl;
	test.beRepaired(20);
	std::cout << test.getHitPoints() << std::endl;
	test.beRepaired(20);
	std::cout << test.getHitPoints() << std::endl;
	test.beRepaired(20);
	std::cout << test.getHitPoints() << std::endl;
    return 0;
}
