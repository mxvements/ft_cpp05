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
		Bureaucrat b = a;
		Bureaucrat c(b);
		Bureaucrat d("Bea", 16);

		std::cout << "Cheks, a, b and c should be the same: " << std::endl;

		Bureaucrat e("Paul", 151); //exception upon creation
		
	} catch (const std::exception &e){
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	return (0);
}