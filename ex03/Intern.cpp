/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:34:03 by lucia             #+#    #+#             */
/*   Updated: 2025/03/16 21:19:21 by lucia            ###   ########.fr       */
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
	(void)src;
}
Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

const char *Intern::WrongRequest::what() const throw()
{
	return "(e) Wrong request for the intern.\
	Try \"shrubbery request\", \"robotomy request\"or \"predisential pardon request\"";
}

AForm *Intern::makeForm(std::string request, std::string target)
{
	const std::string requests[3] = {
		"shrubbery request",
		"robotomy request",
		"predisential pardon request"};

	AForm *(*creators[])(std::string) = {
		&ShrubberyCreationForm::create,
		&RobotomyCreationForm::create,
		&PresidentialPardonForm::create};

	for (int i = 0; i < 3; i++)
	{
		if (request == requests[i])
		{
			return creators[i](target);
		}
	}
	
	throw Intern::WrongRequest();
	// return (NULL);
}
