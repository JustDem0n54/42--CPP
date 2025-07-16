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
		AForm* 	makeShrubbery(std::string target);
		AForm* 	makePresident(std::string target);
		AForm* 	makeRobotomy(std::string target);
};

#endif