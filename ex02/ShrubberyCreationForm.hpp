/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:33:13 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 21:25:23 by luciama2         ###   ########.fr       */
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
		
		class OpenFileException : public std::exception
		{
			public :
				const char *what() const throw();
		} ;

	protected:
	
} ;

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &src);

#endif