/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:47:05 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/13 21:41:27 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::~Form(void)
{
	std::cout << "(i) Destructing Form" << std::endl;
}

Form::Form(void) : _is_signed(false), _grade_required(150), _name("default")
{
	std::cout << "(i) Creating default Form" << std::endl;
}

Form::Form(std::string name, int grade_required) : _name(name),
												   _grade_required(grade_required),
												   _is_signed(false)
{
	std::cout << "(i) Creating Form" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()),
							  _grade_required(src.getGradeRequired()),
							  _is_signed(src.getGradeRequired())
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

int Form::getGradeRequired(void) const
{
	return this->_grade_required;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() >= this->getGradeRequired())
		throw Form::GradeTooLowException();
	this->setIsSigned(true);
	b.signForm();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	return os 
			<< "Form : name -> "
			<< f.getName()
			<< f.getIsSigned()
			<< " grade required -> "
			<< f.getGradeRequired();
}
