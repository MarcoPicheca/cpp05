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
	Intern  someRandomIntern;
	Form*   rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->execute(primo);
	return 0;
}