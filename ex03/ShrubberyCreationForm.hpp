#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : virtual public Form
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		void *operator new(size_t memberSize);
		class FileNotOpen : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm();
		std::string getTarget() const;
};

#endif