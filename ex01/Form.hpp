#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const  size_t required_to_sign;
		const  size_t required_to_execute;
	public:
		Form();
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
		size_t getRequiredSign();
		size_t getRequiredExecute();
		bool getSign() const;
};

#endif