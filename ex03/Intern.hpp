/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:34:00 by lucia             #+#    #+#             */
/*   Updated: 2025/03/16 21:56:20 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

class AForm;

class Intern {
	private:
		struct FormEntry {
			std::string _name;
			AForm *(*_creator)(std::string);
		} ;
		static const FormEntry _forms[3];
		
	protected:

	public:
		~Intern(void);
		Intern(void);
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);

		AForm *makeForm(std::string request, std::string target);

		class WrongRequest : public std::exception{
			public:
				const char *what() const throw();	
		};
} ; 
#endif