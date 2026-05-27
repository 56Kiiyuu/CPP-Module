/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:36:39 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 15:26:27 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"

class Contact
{
	private:
		str	f_name;
		str	l_name;
		str	n_name;
		str	phone;
		str	secret;

	public:
		Contact();
		~Contact();
		void	setFname(str f_name);
		void	setLname(str l_name);
		void	setNname(str nan_nameme);
		void	setPhone(str phone);
		void	setSecret(str secret);
		str		getFname();
		str		getLname();
		str		getNname();
		str		getPhone();
		str		getSecret();
};

#endif
