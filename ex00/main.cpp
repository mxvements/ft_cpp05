/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:43:17 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 17:26:55 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("Ana", 1);
	std::cout << a << std::endl;
	std::cout << std::endl;

	Bureaucrat b(a);
	std::cout << b << std::endl;
	try
	{
		b.upgrade(); // exception GradeTooHigh
	}
	catch (std::exception &ex)
	{
		std::cout << "Trying to upgrade the highest grade" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	Bureaucrat c("Carla", 150);
	std::cout << c << std::endl;
	try
	{
		c.downgrade();
	}
	catch (std::exception &ex)
	{
		std::cout << "Tried to downgrade the lowest grade" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	Bureaucrat d;
	d = c;
	std::cout << d << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat e("Esther", 151);
	}
	catch (std::exception &ex)
	{
		std::cout << "Tried to create with grade too low" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	try
	{
		Bureaucrat f("Frida", 0);
	}
	catch (std::exception &ex)
	{
		std::cout << "Tried to create with grade too high" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	return (0);
}