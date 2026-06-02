/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:58:29 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 13:10:35 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name <<": BraiiiiiiinnnzzzZ..." << "\n";
}

Zombie::Zombie(const std::string &in_name)
{
	name = in_name;
}

Zombie::~Zombie()
{
	std::cout << name << "\n";
}
