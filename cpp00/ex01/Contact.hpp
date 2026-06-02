/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:36:39 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 14:06:26 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
	private:
		std::string	f_name;
		std::string	l_name;
		std::string	n_name;
		std::string	phone;
		std::string	secret;

	public:
		Contact();
		~Contact();
		void	setFname(std::string f_name);
		void	setLname(std::string l_name);
		void	setNname(std::string nan_nameme);
		void	setPhone(std::string phone);
		void	setSecret(std::string secret);
		std::string		getFname();
		std::string		getLname();
		std::string		getNname();
		std::string		getPhone();
		std::string		getSecret();
};

#endif
