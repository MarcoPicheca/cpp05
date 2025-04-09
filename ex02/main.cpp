#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm first("shrubbery");
	RobotomyRequestForm second("Robot");
	PresidentialPardonForm third("president");

	Bureaucrat jacson("Jack", 23);

	try
	{
		first.execute(jacson);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		second.execute(jacson);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		third.execute(jacson);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}