/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:06:12 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 16:07:45 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook
{
	private:
		const	int	_max_contacts;
		int			_current_numb;
		int			_nb_contacts;
		Contact		_array[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	search_contact();
};

#endif
