/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:54:28 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/03 16:02:21 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *Zombie1 = newZombie("Bob");
	Zombie1->announce();
	randomChump("Mario");
	delete Zombie1;
}
