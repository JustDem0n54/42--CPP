#ifndef _BRAIN_
	#define _BRAIN_

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(Brain& copy);
		Brain& operator=(Brain& copy);
		~Brain();
};

#endif