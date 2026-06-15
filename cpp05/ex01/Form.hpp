/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:16:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/15 13:27:00 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		Form();
		Form(const std::string name, int sign_grade, int exec_grade);
		Form(const Form &src);
		Form	&operator=(const Form &rhs);
		~Form();

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif
