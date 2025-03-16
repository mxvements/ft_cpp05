/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:42:48 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/16 21:00:11 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYCRETIONFORM_HPP	
# define ROBOTOMYCRETIONFORM_HPP	

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>  

/**
 * • RobotomyRequestForm: Required grades: sign 72, exec 45
 * Makes some drilling noises. Then, informs that <target> has been 
 * robotomized successfully 50% of the time. Otherwise, informs that 
 * the robotomy failed.
 * 
 */
class RobotomyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		virtual ~RobotomyCreationForm(void);
		RobotomyCreationForm(void);
		RobotomyCreationForm(const std::string target);
		RobotomyCreationForm(const RobotomyCreationForm &src);
		RobotomyCreationForm &operator=(const RobotomyCreationForm &src);

		std::string getTarget(void) const;

		void action(void) const;

		static AForm *create(std::string target);
		
		class RobotomyFailureException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;
		
	protected:
	
} ;

std::ostream &operator<<(std::ostream &os, RobotomyCreationForm &src);

#endif