#include "RobotomyRequestForm.hpp"

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		_target = copy.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	// printWhoAmI("Execute di Robotomy Form");
	if (executor.getGrade() > 72)
	{
		throw GradeTooLowException();
	}
	if (executor.getGrade() > 45)
	{
		throw GradeTooLowException();
	}
	srand(time(NULL));
	int caso = rand();
	std::cout << "(Some robotic noise...)\n";
	if (caso % 2 == 0)
		std::cout << _target << " the robotomization has been done successfully!\n";
	else 
		std::cout << _target << " the robotomization failed\n";
}

std::string RobotomyRequestForm::getTarget() const
{
	// printWhoAmI("Getter target robotomy");
	return _target;
}

void*	RobotomyRequestForm::operator new(size_t memberSize)
{
	// printWhoAmI("New robotomy operator");
	return ::operator new(memberSize);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	Form("RobotomyRequestForm", 72, 45)
{
	// printWhoAmI("Copy constructor robotomy");
	_target = copy.getTarget();
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	// printWhoAmI("Default constructor robotomy");
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
