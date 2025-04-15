#include "RobotomyRequestForm.hpp"

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		_target = copy.getTarget();
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	// printWhoAmI("execute di Robotomy Form");
	if (executor.getGrade() > 72)
	{
		delete this;
		throw Form::GradeTooLowException();
	}
	if (executor.getGrade() > 45)
	{
		delete this;
		throw Form::GradeTooLowException();
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
	return _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	Form("RobotomyRequestForm", 72, 45)
{
	_target = copy.getTarget();
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
