#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _is_signed;
		const  size_t _required_to_sign;
		const  size_t _required_to_execute;
	public:
		Form(std::string name, size_t r_to_sign, size_t r_to_execute);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		void beSign(const Bureaucrat& burocrate);
		~Form();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		std::string getName() const;
		size_t getRequiredSign() const;
		size_t getRequiredExecute() const;
		bool getSign() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};
	
// void printWhoAmI(std::string arg);

#endif