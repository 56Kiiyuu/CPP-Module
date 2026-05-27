/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:06:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/05/27 15:26:45 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook
{
	private:
		const	int	max_contacts;
		int			current_numb;
		int			nb_contacts;
		Contact		array[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	search_contact();
};

#endif
