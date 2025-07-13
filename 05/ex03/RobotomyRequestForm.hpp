#ifndef _ROBOTOMYREQUESTFORM_
	#define _ROBOTOMYREQUESTFORM_

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		void execute(Bureaucrat const & bureaucrat) const;
};

#endif