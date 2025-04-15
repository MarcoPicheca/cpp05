#include "AForm.hpp"

size_t Form::getRequiredSign() const
{
	return _required_to_sign;
}

bool Form::getSign() const
{
	return _is_signed;
}

size_t Form::getRequiredExecute() const
{
	return _required_to_execute;
}

Form::Form(std::string name, size_t r_to_sign, size_t r_to_execute) : _name(name),
		_required_to_sign(r_to_sign), _required_to_execute(r_to_execute)
{
	if (_required_to_execute > 150 || _required_to_sign > 150)
		throw Form::GradeTooLowException();
	if (_required_to_execute < 1 || _required_to_sign < 1)
		throw Form::GradeTooHighException();
}

std::string Form::getName() const
{
	return _name;
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

void	Form::beSigned(const Bureaucrat& burocrate)
{
	if (burocrate.getGrade() > Form::getRequiredSign())
		throw (GradeTooLowException());
	std::cout << _name << ": valid grade to sign\n";
	_is_signed = 1;
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