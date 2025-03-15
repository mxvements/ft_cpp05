/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:43:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/15 20:08:24 by luciama2         ###   ########.fr       */
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

		std::string getTraget(void) const;
	
	protected:
	
} ;

#endif