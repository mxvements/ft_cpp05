/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:43:17 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/17 20:14:21 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(void)
{
	/**
	 * errors to check
	 *
	 * on ShrubberyCreationForm
	 * 	execute with a b with too low grade
	 *  sign with a b too low grade
	 * 	try to target a bad file/folder
	 * 
	 * on RobotomyCreationForm
	 * 	just try to execute, 50% should throw error
	 * 	exectwe with too low grade
	 *  execute with too high grade
	 */
	
	std::cout << std::endl;
	//SCF
	try
	{
		ShrubberyCreationForm scf("trees");
		Bureaucrat b("b", 150);  //150 is lower than 145, sign error
		b.signForm(scf);
	} catch (std::exception &ex)
	{
		std::cout << "Tried to sign a SCF with a Bureaucrat with a grade too low" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}
	
	try 
	{
		ShrubberyCreationForm scf("trees");
		Bureaucrat b("b", 142); //142 is lower than 137 but higher than 147, cannot execute form
		// b.signForm(scf);
		// b.executeForm(scf);
		scf.beSigned(b);
		scf.execute(b);		
	} catch (std::exception &ex)
	{
		std::cout << "Tried to execute a SCF with a Bureaucrat with a grade too low" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	try 
	{
		ShrubberyCreationForm scf("invalid_file/trees"); //invalid file
		Bureaucrat b("b", 135); // this should be OK, target01 file with an ASCII tree
		b.signForm(scf);
		b.executeForm(scf);
	} catch (std::exception &ex)
	{
		std::cout << "Tried open an invalid route" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	//RCF
	try
	{
		RobotomyCreationForm rcf("robot");
		Bureaucrat b("b", 75); // 75, lower than 72, cannot sign
		b.signForm(rcf);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Tried to sign the robotomy with a Bureaucrat with too low grade" << std::endl;
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}

	try
	{
		RobotomyCreationForm rcf("robot");
		Bureaucrat b("b", 50); // 50 is lower than 45, cannot execute
		// b.signForm(rcf);
		// b.executeForm(rcf);
		rcf.beSigned(b);
		rcf.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Tried to execute the robotomy with a Bureaucrat with too low grade" << std::endl;
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}

	try
	{
		RobotomyCreationForm rcf("robot");
		Bureaucrat b("b", 35); // ok
		b.signForm(rcf);
		b.executeForm(rcf);
	}
	catch(const std::exception& e)
	{
		std::cerr << "50% of the time robotomy is unsuccessfull" << std::endl;
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	//PCF
	try
	{
		PresidentialPardonForm pcf("idk");
		Bureaucrat b("b", 35); // ok
		b.signForm(pcf);
		b.executeForm(pcf);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Tried to sign the presidential pardon with a Bureaucrat with too low grade" << std::endl;
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}
	
	try
	{
		PresidentialPardonForm pcf("idk");
		Bureaucrat b("b", 15); // ok
		b.signForm(pcf);
		b.executeForm(pcf);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Tried to execute the presidential pardon with a Bureaucrat with too low grade" << std::endl;
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}

	try
	{
		PresidentialPardonForm pcf("idk");
		Bureaucrat b("b", 3); // ok
		b.signForm(pcf);
		b.executeForm(pcf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << std::endl;
	}

	return (0);
}