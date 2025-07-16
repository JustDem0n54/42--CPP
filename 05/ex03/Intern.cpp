#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern& copy)
{
	(void)copy;
}

Intern& Intern::operator=(Intern& copy)
{
	(void)copy;
	return *this;
}

AForm* 	Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* 	Intern::makePresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* 	Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*  Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*forms[3])(const std::string) = {&Intern::makeRobotomy, &Intern::makePresident, &Intern::makeShrubbery};
	for (int i = 0; i < 3; i++)
	{
		if (!name.compare(names[i]))
		{
			std::cout << "Intern creates " << name[i] << std::endl;
			return ((this->*forms[i])(target));
		}
	}
	std::cout << "Form can't be create: invaled name" << std::endl;
	return 0;
}
