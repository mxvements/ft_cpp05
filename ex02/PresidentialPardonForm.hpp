/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:43:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/16 20:25:43 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP	
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

/**
 * PresidentialPardonForm: Required grades: sign 25, exec 5
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.
 * 
 */
class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		std::string getTarget(void) const;

		void action(void) const;
	
	protected:
	
} ;

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm &src);

#endif