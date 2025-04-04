#include "Form.hpp"

size_t Form::getRequiredSign()
{
	return required_to_sign;
}

bool Form::getSign() const
{
	return is_signed;
}

size_t Form::getRequiredExecute()
{
	return required_to_execute;
}

std::string Form::getName() const
{
	return name;
}

Form::Form() : name("Form") , is_signed(0), 
	required_to_sign(39), required_to_execute(15)
{
}

Form::Form(const Form& copy) : name(copy.name), is_signed(copy.is_signed),
	required_to_sign(copy.required_to_sign), required_to_execute(copy.required_to_execute)
{
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)	is_signed = copy.is_signed;
	return *this;
}

void	Form::beSign(const Bureaucrat& burocrate)
{
	if (burocrate.getGrade() < 1)
		throw (GradeTooHighException());
	if (burocrate.getGrade() > 150)
		throw (GradeTooLowException());
	burocrate.getGrade() < required_to_sign ? is_signed = 1 : throw(GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

Form::~Form()
{
}