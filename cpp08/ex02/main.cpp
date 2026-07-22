/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:24:37 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 16:35:12 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int	main()
{
	std::cout << "TEST" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top:  " << mstack.top() << std::endl; // 17

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl; // 1

		// mstack.push(5); remains
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		std::cout << "Elements in MutantStack:" << std::endl;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
	}
	std::cout << "\nTEST (std::list)" << std::endl;
	{
		std::list<int> lstack;

		lstack.push_back(5);
		lstack.push_back(17);

		std::cout << "Top:  " << lstack.back() << std::endl;

		lstack.pop_back();

		std::cout << "Size: " << lstack.size() << std::endl;

		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();

		++it;
		--it;
		std::cout << "Elements in std::list:" << std::endl;
		while (it != ite) 
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
}