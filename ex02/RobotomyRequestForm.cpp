#include "RobotomyRequestForm.hpp"

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy, std::string target) :
	Form(copy.getName(), copy.getRequiredSign(), copy.getRequiredExecute())
{
	if (copy.getRequiredSign() > 72)
	{
		printWhoAmI("costruttore di copia di Robotomy Form");
		throw GradeTooLowException();
	}
	if (copy.getRequiredExecute() > 45)
	{
		printWhoAmI("costruttore di copia di Robotomy Form");
		throw GradeTooLowException();
	}
	std::cout << "(Some robotic noise...)\n";
	rand() % 2 == 0 ?
		std::cout << target << " the robotomization has been done successfully!\n" :
		std::cout << target << " the robotomization failed\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	if (Form::getRequiredSign() > 72)
	{
		printWhoAmI("costruttore di default di Robotomy Form");
		throw GradeTooLowException();
	}
	if (Form::getRequiredExecute() > 45)
	{
		printWhoAmI("costruttore di default di Robotomy Form");
		throw GradeTooLowException();
	}
	std::cout << "(Some robotic noise...)\n";
	rand() % 2 == 0 ?
		std::cout << target << " the robotomization has been done successfully!\n" :
		std::cout << target << " the robotomization failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
