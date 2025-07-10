#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(0)
{}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& copy): _name(copy.getName()), _grade(copy.getGrade())
{}

Bureaucrat& Bureaucrat::operator=(Bureaucrat& copy)
{
	if (this != &copy)
		this->_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::DecrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::IncrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name + " couldn't sign " + form.getName() + " because: " << e.what() << std::endl;
	}
	if (this->_grade <= form.getGradeToSign())
		std::cerr << this->_name + " signed " + form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& Bureaucrat)
{
	out << Bureaucrat.getName() + ", bureaucrat grade " << Bureaucrat.getGrade() << ".";
	return out;
}




