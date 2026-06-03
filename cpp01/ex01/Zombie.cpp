/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:58:29 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 16:03:41 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name <<": BraiiiiiiinnnzzzZ..." << "\n";
}

void	Zombie::setName(const std::string &in_name)
{
	_name = in_name;
}

Zombie::~Zombie()
{
	std::cout << _name << " (DECONSTRUCTOR)\n";
}
