#include "Bureaucrat.hpp"
#include "Form.hpp"

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


	Bureaucrat Mich("Mich", 2);
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
	
	Form bill("bill", 50, 20);
	std::cout << bill << std::endl;
	Mich.signForm(bill);
	std::cout << bill << std::endl;
}