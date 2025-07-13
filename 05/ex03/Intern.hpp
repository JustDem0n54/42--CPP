#ifndef _INTERN_
	#define _INTERN_

#include <string>
#include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern& copy);
		Intern& operator=(Intern& copy);

		AForm*  makeForm(std::string name, std::string target);
};

#endif