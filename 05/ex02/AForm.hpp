#ifndef _AFORM_
	#define _AFORM_

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int _grade_to_sign;
		const int _grade_to_execute;
		bool _status;
	public:
		AForm();
		AForm(std::string name, int to_sign, int to_execute);
		AForm(const AForm& copy);
		virtual ~AForm();
		AForm& operator=(AForm& copy);
		std::string getName() const;
		bool getStatus() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & bureaucrat) const = 0; 


		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif