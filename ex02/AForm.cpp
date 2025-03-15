/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:47:05 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 21:24:46 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm(void)
{
	std::cout << "(i) Destroying Form" << std::endl;
}

AForm::AForm(void) : _name("default"), _is_signed(false), _to_sign_grade(150),
	_to_exec_grade(150)
{
	std::cout << "(i) Creating default Form" << std::endl;
}

AForm::AForm(std::string name, int to_sign_grade,
	int to_exec_grade) : _name(name), _is_signed(false),
	_to_sign_grade(to_sign_grade), _to_exec_grade(to_exec_grade)
{
	if (this->getToSignGrade() < 1 || this->getToExecGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getToSignGrade() > 150 || this->getToExecGrade() > 150)
		throw AForm::GradeTooLowException();
	std::cout << "(i) Creating Form" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src.getName()),
	_is_signed(src.getToSignGrade()), _to_sign_grade(src.getToSignGrade()),
	_to_exec_grade(src.getToExecGrade())
{
	std::cout << "(i) Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_is_signed = src.getIsSigned();
	}
	std::cout << "(i) Copy assignment called" << std::endl;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_is_signed);
}

void AForm::setIsSigned(bool is_signed)
{
	this->_is_signed = is_signed;
}

int AForm::getToSignGrade(void) const
{
	return (this->_to_sign_grade);
}

int AForm::getToExecGrade(void) const
{
	return (this->_to_exec_grade);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getToSignGrade())
		throw AForm::GradeTooLowException();
	this->setIsSigned(true);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getToExecGrade())
		throw AForm::GradeTooLowException();
	action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("(e) Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("(e) Grade too low!");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("(e) Cannot execute form, needs to be signed first!");
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	return (
		os 
		<< "Form : name -> " 
		<< f.getName() 
		<< ", is signed -> " 
		<< f.getIsSigned() 
		<< ", grade required to sign -> " 
		<< f.getToSignGrade() 
		<< ", grade required to execute -> " 
		<< f.getToExecGrade()
		);
}
