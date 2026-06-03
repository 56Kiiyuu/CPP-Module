/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:24:26 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 15:55:41 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{}

HumanB::~HumanB()
{
	std::cout << this->_name << " died. (DECONSTRUCTOR)\n";
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << "\n";
	else
		std::cout << this->_name << " has no weapon !\n";
}
