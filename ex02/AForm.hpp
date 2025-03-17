/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:47:21 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/17 19:49:43 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _is_signed;
	const int _to_sign_grade;
	const int _to_exec_grade;

  protected:
	virtual void action(void) const = 0;

  public:
	virtual ~AForm(void);
	AForm(void);
	AForm(std::string name, int to_sign_grade, int to_exec_grade);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);

	std::string getName(void) const;
	bool getIsSigned(void) const;
	void setIsSigned(bool is_signed);
	int getToSignGrade(void) const;
	int getToExecGrade(void) const;

	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif