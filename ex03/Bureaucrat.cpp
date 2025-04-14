#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const str, int num) : name(str)
{
	if (num >= 1 && num <= 150)
		grade = num;
	else if (num > 150)
	{
		std::cout << str << '\n';
		throw(GradeTooLowException());	
	}
	else if (num < 1)
	{
		std::cout << str << '\n';
		throw(GradeTooHighException());	
	}
}

Bureaucrat::Bureaucrat() : name ("Default"){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name){
	grade = copy.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
	{
		grade = copy.grade;
	}
	return *this;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		return throw(GradeTooLowException());
	else
		grade++;
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		return throw(GradeTooHighException());
	else
		grade--;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
	os << B.getName() << ", bureaucrat grade " << B.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(Form& f)
{
	f.beSign(*this);
	f.getSign() == 1 ? std::cout << name << " signed " << f.getName() << std::endl
	: std::cout << name << " couldn't sign " << f.getName() << " because grade wasn't high enough.\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::string const Bureaucrat::getName() const{
	return name;
}


size_t Bureaucrat::getGrade() const{
	return grade;
}