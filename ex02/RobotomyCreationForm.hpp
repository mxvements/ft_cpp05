/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:42:48 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 20:07:52 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYCRETIONFORM_HPP	
# define ROBOTOMYCRETIONFORM_HPP	

# include "AForm.hpp"

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

		std::string getTraget(void) const;
		
		class RobotomyFailureException : public std::exception
		{
			public:
				const char *what() const throw();
		} ;
		
	protected:
	
} ;

#endif