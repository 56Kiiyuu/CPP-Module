/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:54:28 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/02 13:15:16 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *Zombie1 = newZombie("Bob");
	Zombie1->announce();
	randomChump("me mario");
	delete Zombie1;
}
