/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:47:05 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 19:38:59 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form(void)
{
	std::cout << "(i) Destroying Form" << std::endl;
}

Form::Form(void)
	: _name("default"),
	  _is_signed(false),
	  _to_sign_grade(150),
	  _to_exec_grade(150)
{
	std::cout << "(i) Creating default Form" << std::endl;
}

Form::Form(std::string name, int to_sign_grade, int to_exec_grade)
	: _name(name),
	  _is_signed(false),
	  _to_sign_grade(to_sign_grade),
	  _to_exec_grade(to_exec_grade)
{
	if (this->getToSignGrade() < 1 || this->getToExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getToSignGrade() > 150 || this->getToExecGrade() > 150)
		throw Form::GradeTooLowException();
	std::cout << "(i) Creating Form" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()),
							  _is_signed(src.getToSignGrade()),
							  _to_sign_grade(src.getToSignGrade()),
							  _to_exec_grade(src.getToExecGrade())
{
	std::cout << "(i) Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_is_signed = src.getIsSigned();
	}
	std::cout << "(i) Copy assignment called" << std::endl;
	return (*this);
}

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_is_signed;
}

void Form::setIsSigned(bool is_signed)
{
	this->_is_signed = is_signed;
}

int Form::getToSignGrade(void) const
{
	return this->_to_sign_grade;
}

int Form::getToExecGrade(void) const
{
	return this->_to_exec_grade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->getToSignGrade())
		throw Form::GradeTooLowException();
	this->setIsSigned(true);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "(e) Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "(e) Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	return os
		   << "Form : name -> "
		   << f.getName()
		   << ", is signed -> "
		   << f.getIsSigned()
		   << ", grade required to sign -> "
		   << f.getToSignGrade()
		   << ", grade required to execute -> "
		   << f.getToExecGrade();
}
