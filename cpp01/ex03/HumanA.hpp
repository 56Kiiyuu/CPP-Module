/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:00:26 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 15:52:21 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon	&_weapon;
		std::string	_name;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack();
};

#endif
