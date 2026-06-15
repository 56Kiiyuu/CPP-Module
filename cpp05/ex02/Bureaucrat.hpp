/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:28:46 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/15 13:31:08 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat	&operator=(const Bureaucrat &src);
		~Bureaucrat();

		void	incrementGrade(void);
		void	decrementGrade(void);

		std::string	getName(void) const;
		int	getGrade(void) const;
		void	signAForm(AForm &AForm);
		void	executeForm(AForm const & form) const;

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Too Low, lowest possible is 150.";
			}
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Too High, highest possible is 1.";
			}
		};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);
#endif
