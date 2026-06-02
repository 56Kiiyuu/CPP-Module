/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:54:28 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 13:41:08 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *Zombie1 = zombieHorde(7, "Zombies");
	Zombie1[0].announce();
	Zombie1[1].announce();
	Zombie1[2].announce();
	Zombie1[3].announce();
	Zombie1[4].announce();
	Zombie1[5].announce();
	Zombie1[6].announce();
	delete[] Zombie1;
}
