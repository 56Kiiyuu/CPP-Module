/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:59:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/06/12 14:10:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "CORRECT TESTS\n";
	try
	{
		Bureaucrat kevin("Kevin", 2);
		std::cout << kevin << "\n";
		kevin.incrementGrade(); //increment to 1
		std::cout << "After incrementation : " << kevin << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception catch : "<< e.what() << '\n';
	}

	std::cout << "\nTEST TOO HIGH\n";
	try
	{
		Bureaucrat boss("Boss", 1);
		boss.incrementGrade(); //increment to 0 (too high)
		std::cout << "After incrementation : " << boss << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception catch : "<< e.what() << '\n';
	}

	std::cout << "\nTEST TOO LOW\n";
	try
	{
		Bureaucrat intern("Intern", 150);
		intern.decrementGrade(); //increment to 151 (too low)
		std::cout << "After incrementation : " << intern << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception catch : "<< e.what() << '\n';
	}
}
