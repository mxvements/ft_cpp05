/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:43:17 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/08 13:25:10 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat a("Ana", 1);
		std::cout << a << std::endl;

		Bureaucrat b;
		b = a;
		b.downgrade();
		std::cout << b << std::endl;
		
		Bureaucrat c(a);
		// c.upgrade(); //exception GradeTooHigh
		std::cout << c << std::endl;
		
		Bureaucrat d("Daniela", 16);
		d.upgrade();
		std::cout << d << std::endl;

		Bureaucrat e("Paul", 151); //exception GradeTooLow
		
	} catch (const std::exception &e){
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	return (0);
}