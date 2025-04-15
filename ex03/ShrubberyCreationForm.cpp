#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::FileNotOpen::what() const throw()
{
	return "Could't open file for the ascii tree";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		_target = copy.getTarget();
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 145)
	{
		delete this;
		throw Form::GradeTooLowException();
	}
	if (executor.getGrade() > 137)
	{
		delete this;
		throw Form::GradeTooLowException();
	}
	std::string target = this->getTarget();
	target.append("_shrubbery");
	const char *target_str = target.c_str();
	std::ofstream ascii_tree(target_str);
	if (!ascii_tree.is_open())
	{
		throw FileNotOpen();
	}
	ascii_tree << "    *\n   /.\\\n  /...\\\n /.....\\\n/.......\\\n    ..\n    ..\n";
	ascii_tree.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form("ShrubberyCreationForm", copy.getRequiredSign(), copy.getRequiredExecute())
{
	_target = copy.getTarget();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	// printWhoAmI("costruttore ShrubberyCreationForm");
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

