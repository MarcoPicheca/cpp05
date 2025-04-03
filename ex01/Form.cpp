#include "Form.hpp"

const size_t Form::getRequiredSign()
{
	return required_to_sign;
}

bool Form::getSign() const
{
	return is_signed;
}

const size_t Form::getRequiredExecute()
{
	return required_to_execute;
}

std::string Form::getName() const
{
	return name;
}

Form::Form() : name("None") , is_signed(0), 
	required_to_execute(15), required_to_sign(7)
{
}

Form::Form(const Form& copy) : name(copy.name), is_signed(copy.is_signed),
	required_to_execute(copy.required_to_execute), required_to_sign(copy.required_to_sign)
{
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)	is_signed = copy.is_signed;
	return *this;
}

void	Form::beSign(const Bureaucrat& burocrate)
{
	burocrate.getGrade() > required_to_sign ? is_signed = 1 : throw(GradeTooLowException());
}


Form::~Form()
{
}