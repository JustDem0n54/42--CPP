#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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


	RobotomyRequestForm test("Robot");
	Mich.signForm(test);
	Mich.executeForm(test);
}