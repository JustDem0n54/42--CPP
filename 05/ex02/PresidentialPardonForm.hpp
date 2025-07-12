#ifndef _PRESIDENTIALPARDONFORM_
	#define _PRESIDENTIALPARDONFORM_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		void execute(Bureaucrat const & bureaucrat) const;
};

#endif