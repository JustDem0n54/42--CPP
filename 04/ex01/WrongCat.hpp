#ifndef _WRONGCAT_
	#define _WRONGCAT_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	public:
		WrongCat();
		WrongCat(WrongCat& copy);
		WrongCat& operator=(WrongCat& copy);
		~WrongCat();
};

#endif 