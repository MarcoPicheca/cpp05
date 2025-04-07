#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
	Form::Form(copy.getName(), copy.getRequiredSign(), copy.getRequiredExecute())
{
	if (copy.getRequiredSign() > 25)
	{
		printWhoAmI("costruttore presidential pardon form");
		throw Form::GradeTooLowException();
	}
	if (copy.getRequiredExecute() > 5)
	{
		printWhoAmI("costruttore presidential pardon form");
		throw Form::GradeTooLowException();
	}
	std::cout << copy.getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	if (Form::getRequiredSign() > 25)
	{
		printWhoAmI("costruttore presidential pardon form");
		throw Form::GradeTooLowException();
	}
	if (Form::getRequiredExecute() > 5)
	{
		printWhoAmI("costruttore presidential pardon form");
		throw Form::GradeTooLowException();
	}
	std::cout << Form::getName() << " has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
