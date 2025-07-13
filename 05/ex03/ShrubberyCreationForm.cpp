#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy)
{
	this->_target = copy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getStatus())
		throw AForm::NotSignedException();
	std::ofstream file((this->_target + "_shrubbery").c_str());
	if (file)
	{
		file << "      ^^^		      ^^^		\n";
		file << "     ^^^^^		     ^^^^^		\n";
		file << "    ^^^^^^^         ^^^^^^^		\n";
		file << "   ^^^^^^^^^	   ^^^^^^^^^	\n";
		file << "  ^^^^^^^^^^^	  ^^^^^^^^^^^	\n";
		file << "      |||		      |||		\n";
		file << "      |||		      |||		\n";
	}
	else 
		std::cout << "File can not be create." << std::endl;
}