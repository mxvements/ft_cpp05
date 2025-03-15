/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:51:49 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 16:54:59 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

/**
 * custom exceptions in c++
 * 
 * syntax of what() inheritance:
 * 		const char *what() const throw(){}
 * 		const char *what() const noexcept override {}
 * what() is declared in exception as virtual, so it can be overrided, 
 * calling what() retrieves and error message
 * noexcept/throw() is to garantee what() will not throw an exception
 */
class Form;
class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		virtual ~Bureaucrat(void);
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		
		std::string getName(void) const;
		int getGrade(void) const;

		void downgrade(void);
		void upgrade(void);
		void signForm(Form &f) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;

} ;

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif