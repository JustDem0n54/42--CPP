#ifndef _ZOMBIE_
	#define _ZOMBIE_

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce();
		void set_name(std::string);
};

#endif