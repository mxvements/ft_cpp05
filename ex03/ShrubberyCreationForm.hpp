/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:33:13 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/16 21:01:10 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

/**
 * ShrubberyCreationForm: Required grades: sign 145, exec 137
 * Create a file <target>_shrubbery in the working directory, 
 * and writes ASCII treesinside it
 * 
 */
class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		virtual ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		std::string getTarget(void) const;
		
		void action(void) const;

		static AForm *create(std::string target);
		
		class OpenFileException : public std::exception
		{
			public :
				const char *what() const throw();
		} ;

	protected:
	
} ;

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &src);

#endif