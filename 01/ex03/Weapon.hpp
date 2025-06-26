#ifndef _WEAPON_
	#define _WEAPON_

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string& getType(void) const;
		void setType(std::string new_type);
};


#endif