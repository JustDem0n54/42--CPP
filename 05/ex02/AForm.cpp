#include "AForm.hpp"

AForm::AForm(): _name("default"), _grade_to_sign(150), _grade_to_execute(150), _status(false)
{}

AForm::AForm(std::string name, int to_sign, int to_execute): _name(name), _grade_to_sign(to_sign), _grade_to_execute(to_execute), _status(false)
{
	if (to_sign > 150 || to_execute > 150)
		throw AForm::GradeTooLowException();
	if (to_sign < 1 || to_execute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& copy): _name(copy._name), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute), _status(copy._status)
{}

AForm::~AForm()
{}

AForm& AForm::operator=(AForm& copy)
{
	if (this != &copy)
	{
		this->_status = copy._status;
	}
	return *this;
}


std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getStatus() const
{
	return this->_status;
}

int AForm::getGradeToSign() const
{
	return this->_grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->_grade_to_execute;
}


std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	if (AForm.getStatus() == true)
	{
		out << "AForm : " + AForm.getName() + " - Grade to sign: " << AForm.getGradeToSign()
		<< " - Grade to execute: " << AForm.getGradeToSign() << " - Signed: yes";
	}
	else
	{
		out << "AForm : " + AForm.getName() + " - Grade to sign: " << AForm.getGradeToSign()
		<< " - Grade to execute: " << AForm.getGradeToSign() << " - Signed: no";		
	}
	return out;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_status = true;
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
}
