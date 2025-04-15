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
	int i = 0;
	while (i < 3)
	{
		if (formName.compare(arr_name[i]) == 0)
			break ;
		i++;
	}
	switch (i)
	{
		case 0: 
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(formTarget);
		case 1: 
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(formTarget);
	}
	std::cerr << "No such Form type " << formName << std::endl;
	return ((Form *)NULL);
}

Intern::~Intern()
{
}
