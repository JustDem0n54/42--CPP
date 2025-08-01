#ifndef _BUREAUCRAT_
	#define _BUREAUCRAT_

#include <string>
#include <iostream>

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
		
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat);

#endif