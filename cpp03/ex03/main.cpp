/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:12:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/09 15:28:42 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	std::cout << "CONSTRUCTORS\n";
	DiamondTrap diamo("Didi");

	std::cout << "\nSTATS and FUNCTIONS\n";
	diamo.whoAmI();
	diamo.attack("a poor target"); //print msg scavtrap

	std::cout << "\nHERITAGE CAPACITIES\n";
	diamo.guardGate();     // Capacité de ScavTrap
	diamo.highFivesGuys(); // Capacité de FragTrap

	std::cout << "\nDESTRUCTORS\n";
	return 0;
}
