#ifndef INTERN_HPP
#define INTERN_HPP
#include "iostream"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();
		Form* makeForm(std::string formName, std::string formTarget);
};

#endif