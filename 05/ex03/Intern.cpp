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

AForm*  Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* forms[3];
	forms[0] = new RobotomyRequestForm(target);
	forms[1] = new PresidentialPardonForm(target);
	forms[2] = new ShrubberyCreationForm(target);
	for (int i = 0; i < 3; i++)
	{
		if (!name.compare(names[i]))
		{
			std::cout << "Intern creates " << forms[i]->getName() << std::endl;
			return forms[i];
		}
	}
	std::cout << "Form can't be create: invaled name" << std::endl;
	return 0;
}
