/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:43:17 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 18:18:21 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	/**
	 * Errors to handle on Form:
	 * 
	 * create a form with a grade too high to sign
	 * create a form with a grede too low to sign
	 * 
	 * create a form with a grade too high to execute
	 * create a form with a grade too low to execute
	 * 
	 * sign a form with a bureaucrat with a grade too low to sign
	 * 
	 */

	Form a("A1", 1, 1);
	std::cout << a << std::endl;
	std::cout << std::endl;

	try {
		Form b("B2", 0, 1);
	} catch (std::exception &ex) {
		std::cout << "Tried to create a from with a grade too high to sign" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}
	
	try {
		Form b("B2", 1, 0);
	} catch (std::exception &ex) {
		std::cout << "Tried to create a from with a grade too high to execute" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	try {
		Form b("B2", 151, 150);
	} catch (std::exception &ex) {
		std::cout << "Tried to create a from with a grade too low to sign" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}
	
	try {
		Form b("B2", 150, 151);
	} catch (std::exception &ex) {
		std::cout << "Tried to create a from with a grade too low to execute" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}

	Bureaucrat b("Bea", 2);
	try {
		b.signForm(a);
	} catch (std::exception &ex){
		std::cout << "Tried to sign a form with a bureaucrat with a grade too low" << std::endl;
		std::cout << ex.what() << std::endl;
		std::cout << std::endl;
	}
	
	b.upgrade();
	b.signForm(a);
	
	return (0);
}