/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:59:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/15 14:55:23 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Intern		someRandomIntern;
	Bureaucrat	boss("Boss", 1);
	AForm* rrf;

	std::cout << "Invalid Form (ROBOTOMY)\n";
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		boss.signAForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf; // for no leaks
	}

	std::cout << "\nValid Form (PRESIDENTIAL)\n";
	rrf = someRandomIntern.makeForm("presidential pardon", "Arthur");
	if (rrf) {
		boss.signAForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf; // for no leaks
	}

	std::cout << "\nInvalid Form\n";
	rrf = someRandomIntern.makeForm("coffee request", "Boss"); //doesnt exist
	if (rrf) {
		boss.signAForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf; // for no leaks
	}

	return 0;
}
