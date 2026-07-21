/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:10:57 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/21 15:16:47 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"

Base * generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main()
{
	std::srand(std::time(NULL));

	std::cout << "TEST 5 RANDOM OBJ\n" << std::endl;
	for (int i = 1; i < 6; i++)
	{
		Base* obj = generate();

		std::cout << "Object " << i << ":" << std::endl;
		std::cout << "Pointer identification:     ";
		identify(obj);

		std::cout << "Reference identification:   ";
		identify(*obj);

		std::cout << std::endl;
		delete obj;
	}
}
