/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:25:24 by lucia             #+#    #+#             */
/*   Updated: 2025/03/16 20:59:01 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "(i) Destroying PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5),
	  _target("none")
{
	std::cout << "(i) Creating a default PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5),
	  _target(target)
{
	std::cout << "(i) Creating a PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm("PresidentialPardonForm", 25, 5),
	  _target(src._target)
{
	std::cout << "(i) Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return (*this);
}

// getter
std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

// member functions
void PresidentialPardonForm::action(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

//<<
std::ostream &operator<<(std::ostream &os, PresidentialPardonForm &src)
{
	return (
		os << "PresidentialPardonForm: (name, isSigned, gradeToSign, gradeToExecute, Taget) -> "
		<< src.getName()
		<< src.getIsSigned()
		<< src.getToSignGrade()
		<< src.getToExecGrade()
		<< src.getTarget()
	);
}

AForm *PresidentialPardonForm::create(std::string target)
{
	return new PresidentialPardonForm(target);
}