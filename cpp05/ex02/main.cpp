/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:59:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/15 14:12:28 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>



int main() {
	std::srand(std::time(NULL)); // INIT FOR ROBOTOMY

    Bureaucrat boss("Boss", 1);
    Bureaucrat middle("Bob", 50);
    Bureaucrat low("Intern", 140);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur");

    std::cout << "EXEC WITHOUT SIGNATURE\n";
    boss.executeForm(shrub); // Should fail (Not signed)

    std::cout << "\nSIGNATURE AND EXEC SHRUBBERY\n";
    low.signAForm(shrub); // OK (Intern 140, requires 145)
    low.executeForm(shrub); // KO (Intern 140, requires 137)
    middle.executeForm(shrub); // OK (Bob  50 -> create garden_shrubbery)

    std::cout << "\nROBOTOMY (50% CHANCE)\n";
    middle.signAForm(robot); // OK (Bob 50, requires 72)
    middle.executeForm(robot); // KO(Bob 50, requires 45)
    boss.executeForm(robot); // OK (Launch)

    std::cout << "\nPRESIDENTIAL PARDON\n";
    boss.signAForm(pardon);
    boss.executeForm(pardon); // OK

    return 0;
}
