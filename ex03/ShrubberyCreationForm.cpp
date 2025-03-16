/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:09:38 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/16 21:01:54 by lucia            ###   ########.fr       */
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

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	std::cout << "(i) Copy assignment called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShrubberyCreationForm", 147, 137),
	  _target(src._target)
{
	std::cout << "(i) Copy constructor called" << std::endl;
}

// getters
std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

// exceptions
const char *ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return "(e) Open file exception";
}

// instance methods
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

//<< operator
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

AForm *ShrubberyCreationForm::create(std::string target)
{
	return new ShrubberyCreationForm(target);
}