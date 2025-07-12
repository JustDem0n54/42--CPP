#include "Form.hpp"

Form::Form(): _name("default"), _grade_to_sign(150), _grade_to_execute(150), _status(false)
{}

Form::Form(std::string name, int to_sign, int to_execute): _name(name), _grade_to_sign(to_sign), _grade_to_execute(to_execute), _status(false)
{
	if (to_sign > 150 || to_execute > 150)
		throw Form::GradeTooLowException();
	if (to_sign < 1 || to_execute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& copy): _name(copy._name), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute), _status(copy._status)
{}

Form::~Form()
{}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
	{
		this->_status = copy._status;
	}
	return *this;
}


std::string Form::getName() const
{
	return this->_name;
}

bool Form::getStatus() const
{
	return this->_status;
}

int Form::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->_grade_to_execute;
}


std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	if (Form.getStatus())
	{
		out << "Form : " + Form.getName() + " - Grade to sign: " << Form.getGradeToSign()
		<< " - Grade to execute: " << Form.getGradeToSign() << " - Signed: yes";
	}
	else
	{
		out << "Form : " + Form.getName() + " - Grade to sign: " << Form.getGradeToSign()
		<< " - Grade to execute: " << Form.getGradeToSign() << " - Signed: no";		
	}
	return out;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_status = 0;
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
}
