#include "Form.hpp"

size_t Form::getRequiredSign()
{
	return _required_to_sign;
}

bool Form::getSign() const
{
	return _is_signed;
}

size_t Form::getRequiredExecute()
{
	return _required_to_execute;
}

Form::Form(std::string name, size_t r_to_sign, size_t r_to_execute) : _name(name),
		_required_to_sign(r_to_sign), _required_to_execute(r_to_execute)
{
}

std::string Form::getName() const
{
	return _name;
}

Form::Form() : _name("Form") , _is_signed(0), 
	_required_to_sign(39), _required_to_execute(15)
{
}

Form::Form(const Form& copy) : _name(copy._name), _is_signed(copy._is_signed),
	_required_to_sign(copy._required_to_sign), _required_to_execute(copy._required_to_execute)
{
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)	_is_signed = copy._is_signed;
	return *this;
}

void	Form::beSign(const Bureaucrat& burocrate)
{
	if (burocrate.getGrade() < 1)
		throw (GradeTooHighException());
	if (burocrate.getGrade() > 150)
		throw (GradeTooLowException());
	burocrate.getGrade() < _required_to_sign ? _is_signed = 1 : throw(GradeTooLowException());
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