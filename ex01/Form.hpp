/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:47:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/13 21:39:49 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form 
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_required;

	public:
		~Form(void);
		Form(void);
		Form(std::string name, int grade_required);
		Form(const Form &src);
		Form &operator=(const Form &src);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		void setIsSigned(bool is_signed);
		int getGradeRequired(void) const;
	
		void beSigned(Bureaucrat &b);
		
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

std::ostream &operator<<(std::ostream &os, const Form &f);

# endif