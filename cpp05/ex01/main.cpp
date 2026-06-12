/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:59:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/12 14:50:06 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "INIT\n";
	Bureaucrat boss("Boss", 10);
	Bureaucrat intern("Intern", 120);

	Form lowForm("Low Level Form", 100, 100);
	Form highForm("Top Secret Form", 5, 5);

	std::cout << lowForm << std::endl;
	std::cout << highForm << std::endl;

	std::cout << "\nTEST SIGNATURE INTERN\n";
	//Intern (120) try to sign a form required 100 = should fail
	intern.signForm(lowForm);
	std::cout << lowForm << std::endl;

	std::cout << "\nTEST SIGNATURE BOSS\n";
	//Boss (10) try to sign a form required 100 -> should success
	boss.signForm(lowForm);
	std::cout << lowForm << std::endl;

	//Boss (10) try to sign a form required 5 -> should fail
	boss.signForm(highForm);

	std::cout << "\nTEST FORMULAIRE INVALID\n";
	try {
		Form illegal("Illegal Form", 0, 50); //Grade 0 unexpected
	}
	catch (const std::exception &e) {
		std::cout << "Exception catch : " << e.what() << std::endl;
	}

	return 0;
}
