/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:04:40 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/08 13:22:53 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "(i) Destroying bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(void) : _name("Jake"), _grade(150)
{
	std::cout << "(i) Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_grade = grade;
		std::cout << "(i) Bureaucrat created" << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	std::cout << "(i) Copy assignement called" << std::endl;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "(i) Copy constructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::downgrade(void)
{
	int down = this->getGrade() + 1;
	if (down > 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = down;
}

void Bureaucrat::upgrade(void)
{
	int up = this->getGrade() - 1;
	if (up < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = up;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return os
		   << "Bureaucrat: name -> "
		   << b.getName()
		   << ", grade -> "
		   << b.getGrade();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}