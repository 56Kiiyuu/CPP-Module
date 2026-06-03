/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:04:30 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 15:55:31 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)
{
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " died. (DECONSTRUCTOR)\n";
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "\n";
}
