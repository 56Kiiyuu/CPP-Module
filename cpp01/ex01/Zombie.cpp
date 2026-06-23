/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:58:29 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/23 16:32:48 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string &in_name)
{
	_name = in_name;
}

Zombie::~Zombie()
{
	std::cout << _name << " (DECONSTRUCTOR)\n";
}
