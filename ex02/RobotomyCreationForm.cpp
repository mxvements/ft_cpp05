/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:30:07 by lucia             #+#    #+#             */
/*   Updated: 2025/03/16 19:20:52 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyCreationForm.hpp"

RobotomyCreationForm::~RobotomyCreationForm(void)
{
	std::cout << "(i) Destroying RobotomyCreationForm" << std::endl;
}

RobotomyCreationForm::RobotomyCreationForm(void)
	: AForm("RobotomyCreationForm", 72, 45),
	  _target("none")
{
	std::cout << "(i) Creating a default RobotomyCreationForm" << std::endl;
}

RobotomyCreationForm::RobotomyCreationForm(std::string target)
	: AForm("RobotomyCreationForm", 72, 45),
	  _target(target)
{
	std::cout << "(i) Creating a RobotomyCreationForm" << std::endl;
}

RobotomyCreationForm::RobotomyCreationForm(const RobotomyCreationForm &src)
	: AForm("RobotomyCreationForm", 72, 45),
	  _target(src._target)
{
	std::cout << "(i) Copy constructor called" << std::endl;
}

RobotomyCreationForm &RobotomyCreationForm::operator=(const RobotomyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return (*this);
}

// getters
std::string RobotomyCreationForm::getTarget(void) const
{
	return this->_target;
}

// exceptions
const char *RobotomyCreationForm::RobotomyFailureException::what() const throw()
{
	return "(e) Robotomy failed";
}

// methods
void RobotomyCreationForm::action(void) const
{
	std::srand(std::time(0)); //seed
	double random_number = static_cast<double>(std::rand()) / RAND_MAX;

	if (random_number <= 0.5)
	{
		std::cout << this->getTarget() << " has been robotimized successfully!" << std::endl;
	}
	else
	{
		throw RobotomyCreationForm::RobotomyFailureException();
	}
}
