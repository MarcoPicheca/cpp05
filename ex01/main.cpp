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

	Bureaucrat spino("spinotto", 12);
	Bureaucrat copia(spino);
	Bureaucrat copia2;

	copia2.operator=(spino);
	spino.decrementGrade();
	std::cout << spino;
	spino.incrementGrade();
	std::cout << spino;
	std::cout << copia;
	std::cout << copia2;
	return 0;
}
