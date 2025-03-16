/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:34:03 by lucia             #+#    #+#             */
/*   Updated: 2025/03/16 21:57:48 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyCreationForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::~Intern(void) {}
Intern::Intern(void) {}

Intern::Intern(const Intern &src)
{
	*this = src;
}
Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

const char *Intern::WrongRequest::what() const throw()
{
	return "(e) Wrong request for the intern. Try \"shrubbery request\", \"robotomy request\"or \"predisential pardon request\"";
}
// static array of options for the intern class
const Intern::FormEntry Intern::_forms[3] = {
	{"PresidentialPardonForm", &PresidentialPardonForm::create},
	{"RobotomyCreationForm", &RobotomyCreationForm::create},
	{"ShrubberyCreationForm", &ShrubberyCreationForm::create}};

AForm *Intern::makeForm(std::string request, std::string target)
{	
	//first solution provided:
	
	// const std::string requests[3] = {
	// 	"shrubbery request",
	// 	"robotomy request",
	// 	"predisential pardon request"};

	// AForm *(*creators[])(std::string) = {
	// 	&ShrubberyCreationForm::create,
	// 	&RobotomyCreationForm::create,
	// 	&PresidentialPardonForm::create};

	for (int i = 0; i < 3; i++)
	{
		if (request == Intern::_forms[i]._name)
		{
			std::cout << "Intern creates " << request << std::endl;
			return Intern::_forms[i]._creator(target);
		}
	}

	throw Intern::WrongRequest();
	// return (NULL);
}
