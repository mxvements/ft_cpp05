/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:43:17 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 21:29:50 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	/**
	 * errors to check
	 *
	 * on ShrubberyCreationForm
	 * 	execute with a b with too low grade
	 *  sign with a b too low grade
	 * 	openfileexception?
	 */
	
	
	try
	{
		ShrubberyCreationForm scf("trees");
		Bureaucrat b1("b1", 150);  //150 is lower than 145, sign error
		b1.signForm(scf);
	} catch (std::exception &ex)
	{
		std::cout << "Tried to sign a SCF with a Bureaucrat with a grade too low" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}
	
	try 
	{
		ShrubberyCreationForm scf("trees");
		Bureaucrat b1("b1", 142); //142 is lower than 137 but higher than 147, cannot execute form
		b1.signForm(scf);
		b1.executeForm(scf);
	} catch (std::exception &ex)
	{
		std::cout << "Tried to execute a SCF with a Bureaucrat with a grade too low" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	try 
	{
		ShrubberyCreationForm scf("invalid_file/trees");
		Bureaucrat b1("b1", 135); // this should be OK, target01 file with an ASCII tree
		b1.signForm(scf);
		b1.executeForm(scf);
	} catch (std::exception &ex)
	{
		std::cout << "Tried open an invalid route" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	return (0);
}