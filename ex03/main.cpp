/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:43:17 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/16 21:59:50 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl;
		Intern newIntern;
		AForm *f = newIntern.makeForm("RandomRequest", "target");
		delete f;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Intern newIntern;
		AForm *f = newIntern.makeForm("PresidentialPardonForm", "Ana");
		Bureaucrat b("Pauline", 1);
		// f->beSigned(b);
		// f->execute(b);
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Intern newIntern;
		AForm *f = newIntern.makeForm("ShrubberyCreationForm", "trees");
		Bureaucrat b("Pauline", 1);
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}

	try
	{
		std::cout << std::endl;
		Intern newIntern;
		AForm *f = newIntern.makeForm("ShrubberyCreationForm", "random_folder/trees");
		Bureaucrat b("Pauline", 1);
		try
		{
			b.signForm(*f);
			b.executeForm(*f); // error on file, this should throw an error
		}
		catch (const std::exception &ex)
		{
			std::cout << ex.what() << std::endl; //OpenFileException
		}
		delete f;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}

	return (0);
}