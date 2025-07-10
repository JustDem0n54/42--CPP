#ifndef _FORM_
	#define _FORM_

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _grade_to_sign;
		const int _grade_to_execute;
		bool _status;
	public:
		Form();
		Form(std::string name, int to_sign, int to_execute);
		Form(Form& copy);
		~Form();
		Form& operator=(Form& copy);
		std::string getName() const;
		bool getStatus() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat& bureaucrat);


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

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif