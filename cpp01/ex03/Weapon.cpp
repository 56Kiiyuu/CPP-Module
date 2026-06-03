/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:53:24 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 15:55:49 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon)
{
	this->setType(weapon);
}

Weapon::~Weapon()
{
	std::cout << this->getType() << " dropped to the floor and broke. (DECONSTRUCTOR)" << std::endl;
}

std::string Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(const std::string &weapon)
{
	_type = weapon;
}
