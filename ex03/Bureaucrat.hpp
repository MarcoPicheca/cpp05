#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string		name;
		size_t		 	grade;
	public:
		Bureaucrat(std::string const str, int num);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();
		Bureaucrat();
		void 	signForm(Form &f);
		void	decrementGrade();
		void	incrementGrade();
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
				
		std::string const getName() const;
		size_t getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);

#endif