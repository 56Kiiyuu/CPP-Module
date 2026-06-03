/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:53:39 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 15:52:25 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(const std::string &weapon);
		~Weapon();
		std::string	getType() const;
		void		setType(const std::string &weapon);
};

#endif
