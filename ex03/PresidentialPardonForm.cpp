#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
	Form::Form(copy.getName(), copy.getRequiredSign(), copy.getRequiredExecute())
{
	_target = copy.getTarget();
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 25)
	{
		delete this;
		throw Form::GradeTooLowException();
	}
	if (executor.getGrade() > 5)
	{
		delete this;
		throw Form::GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
		_target = copy.getTarget(); 
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	_target  = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
