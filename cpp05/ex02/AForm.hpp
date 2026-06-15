/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:16:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/15 13:16:28 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
		const std::string	_target;
	public:
		AForm();
		AForm(const std::string name, int sign_grade, int exec_grade, const std::string target);
		AForm(const AForm &src);
		AForm	&operator=(const AForm &rhs);
		~AForm();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		std::string	getTarget() const;

		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(Bureaucrat const & executor) const;
		virtual void	executeAction() const = 0;

		class GradeTooLowException : public std::exception
			{
				public:
					virtual const char* what() const throw()
					{
						return "Grade is too low !";
					}
			};

		class GradeTooHighException : public std::exception
			{
				public:
					virtual const char* what() const throw()
					{
						return "Grade is too high !";
					}
			};

		class FormNotSignedException : public std::exception
			{
				public:
					virtual const char* what() const throw()
					{
						return "Form cannot be executed because it is not signed!";
					}
			};
};

std::ostream &operator<<(std::ostream &o, const AForm &rhs);

#endif
