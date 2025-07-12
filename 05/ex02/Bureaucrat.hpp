#ifndef _BUREAUCRAT_
	#define _BUREAUCRAT_

#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& copy);
		Bureaucrat& operator=(Bureaucrat& copy);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void IncrementGrade();
		void DecrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const & form) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "The grade is too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "The grade is too Low";
				}
		};
		
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif