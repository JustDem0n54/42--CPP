#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy)
{
	this->_target = copy._target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & bureaucrat) const
{
	std::srand(time(0));
	
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getStatus())
		throw AForm::NotSignedException();
	if (std::rand() % 2 == 1)
		std::cout << "VrrVrrrvVRRRRVvrvrrvrvr " << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}