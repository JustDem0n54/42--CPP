#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat Bob("Bob", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error creation : " << e.what() << std::endl;
	}
	std::cout << "======================================" << std::endl;

	Bureaucrat Mich("Mich", 1);
	std::cout << Mich << std::endl;
	try
	{
		Mich.IncrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Error incrematation : " << e.what() << std::endl;
	}
	std::cout << Mich << std::endl;
	try
	{
		Mich.IncrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Error incrematation : " << e.what() << std::endl;
	}
	std::cout << Mich << std::endl;
	std::cout << "======================================" << std::endl;

	RobotomyRequestForm test("Robot");
	Mich.signForm(test);
	Mich.executeForm(test);
	std::cout << "======================================" << std::endl;

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	Mich.signForm(*rrf);
	Mich.executeForm(*rrf);
	std::cout << "======================================" << std::endl;

	if (rrf)
		delete rrf;
}