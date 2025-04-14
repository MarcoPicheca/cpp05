#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

Form* Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string arr_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	ShrubberyCreationForm a(formTarget);
	RobotomyRequestForm b(formTarget);
	PresidentialPardonForm c(formTarget);
	Form* arr_form[3] = {&a, &b, &c};
	// Form* newForm = (Form *)NULL;
	for (size_t i = 0; i < 3; i++)
	{
		if (formName.compare(arr_name[i]) == 0)
			return arr_form[i];
	}
	std::cout << "Intern creates " << formName << std::endl;
	// if (formName.compare("shrubbery creation") == 0)
	// 	newForm =  new ShrubberyCreationForm(formTarget);
	// else if (formName.compare("robotomy request") == 0)
	// 	newForm =  new RobotomyRequestForm(formTarget);
	// else if (formName.compare("presidential pardon") == 0)
	// 	newForm =  new PresidentialPardonForm(formTarget);
	// else
	// 	std::cout << "No such Form type\n";
	return (NULL);
}

Intern::~Intern()
{
}
