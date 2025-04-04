#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat hoi("orco dio", 39483);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat spin("spino", 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f;
		Bureaucrat firma("Zio", 2);
		Bureaucrat firma2("Zio2", 30);
		firma.signForm(f);
		firma2.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
