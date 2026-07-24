/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:04:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/24 16:11:44 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <cstdlib>
# include <ctime>
# include <algorithm>
# include <sys/time.h>


class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void	sortVector(std::vector<int> &vec);
		void	sortDeque(std::deque<int> &deq);
		std::vector<size_t> generateJacobsthalSequence(size_t n);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		bool parseInput(int argc, char **argv);
		void execute();
};

#endif


