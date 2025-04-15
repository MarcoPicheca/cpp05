#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	cristo;
	Form*	messia;

	Bureaucrat primo("Frank", 24);
	messia = cristo.makeForm("sjdc", "jdjjd");
	delete messia;
	Intern  someRandomIntern;
	Form*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		rrf->beSigned(primo);
		rrf->execute(primo);
		delete rrf;
	}
	try
	{
		rrf = someRandomIntern.makeForm("shrubbery creation", "Alex");
		if (rrf)
		{
			rrf->beSigned(primo);
			rrf->execute(primo);
			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		rrf = someRandomIntern.makeForm("presidential pardon", "Julio");
		if (rrf)
		{
			rrf->beSigned(primo);
			rrf->execute(primo);
			delete rrf;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}