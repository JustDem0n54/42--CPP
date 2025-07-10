#include "Bureaucrat.hpp"

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
	

	Bureaucrat Paul("Paul", 149);
	std::cout << Paul << std::endl;
	try
	{
		Paul.DecrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Error decrematation : " << e.what() << std::endl;
	}
	std::cout << Paul << std::endl;
	try
	{
		Paul.DecrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << "Error decrematation : " << e.what() << std::endl;
	}
	std::cout << Paul << std::endl;
	
}