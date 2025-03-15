/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:09:38 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 21:25:33 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "(i) Destroying ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 147, 137),
	  _target("none")
{
	std::cout << "(i) Creating a default ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 147, 137),
	  _target(target)
{
	std::cout << "(i) Creating ShrubberyCreationForm" << std::endl;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return "(e) Open file exception";
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream asciitree(this->getTarget().c_str());
	if (asciitree.is_open())
	{
		asciitree.clear();
		asciitree << "    *    \n "
					 "   ***   \n"
					 "  *****  \n"
					 " ******* \n"
					 "*********\n"
					 "    |    \n"
					 "    |    \n";
		asciitree.close();
	}
	else
	{
		throw ShrubberyCreationForm::OpenFileException();
	}
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &src)
{
	return (
		os
		<< "ShrubberyCreationForm : name, isSigned, singGrade, execGrade, target -> "
		<< src.getName() << ", "
		<< src.getIsSigned() << ", "
		<< src.getToSignGrade() << ", "
		<< src.getToExecGrade() << ", "
		<< src.getTarget());
}