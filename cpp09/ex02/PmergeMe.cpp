/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:13:21 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/24 17:30:38 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deq(src._deq)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

bool PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::stringstream ss(argv[i]);
		std::string token;

		while (ss >> token)
		{
			for (size_t j = 0; j < token.length(); ++j)
			{
				if (!std::isdigit(token[j]))
					return false;
			}

			char *endptr;
			long val = std::strtol(token.c_str(), &endptr, 10);
			if (*endptr != '\0' || val <= 0 || val > 2147483647)
				return false;

			this->_vec.push_back(static_cast<int>(val));
			this->_deq.push_back(static_cast<int>(val));
		}
	}
	return !this->_vec.empty();
}

// formule suite de Jacobsthal : Jn = Jn-1 + 2 * Jn-2

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
	std::vector<size_t> jacob;
	if (n == 0)
		return jacob;

	jacob.push_back(1);
	if (n == 1)
		return jacob;

	size_t j_prev = 1;
	size_t j_curr = 3;

	while (j_curr <= n)
	{
		jacob.push_back(j_curr);
		size_t next = j_curr + 2 * j_prev;
		j_prev = j_curr;
		j_curr = next;
	}
	return jacob;
}


// FORD JOHNSON (vector)
void	PmergeMe::sortVector(std::vector<int> &vec)
{
	size_t n = vec.size();
	if (n <= 1)
		return;

	// pairs (large, small)
	std::vector<std::pair<int, int> > pairs;
	int orphan = -1;
	bool hasOrphan = (n % 2 != 0);

	for (size_t i = 0; i < n - (hasOrphan ? 1 : 0); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}
	if (hasOrphan)
		orphan = vec[n - 1];

	// Extract mainChain (large)
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
	}

	// recursive sort for mainChain
	sortVector(mainChain);

	// sort "small" to match with large order
	std::vector<int> pend;
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (mainChain[i] == pairs[j].first)
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	// insert the first small (associated with first large)
	if (!pend.empty())
	{
		mainChain.insert(mainChain.begin(), pend[0]);
	}

	// insert other elem with Jacobsthal
	std::vector<size_t> jacob = generateJacobsthalSequence(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	if (!pend.empty())
		inserted[0] = true; //small 1 alrdy insert

	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t index = jacob[i] - 1;
		if (index < pend.size() && !inserted[index])
		{
			std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[index]);
			mainChain.insert(it, pend[index]);
			inserted[index] = true;

			for (size_t j = index - 1; j > 0; --j)
			{
				if (!inserted[j])
				{
					it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);
					mainChain.insert(it, pend[j]);
					inserted[j] = true;
				}
			}
		}
	}

	//insert elem remains that overflows suite
	for (size_t i = 1; i < pend.size(); ++i)
	{
		if (!inserted[i])
		{
			std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
			mainChain.insert(it, pend[i]);
		}
	}

	//insert orphan if one
	if (hasOrphan)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), orphan);
		mainChain.insert(it, orphan);
	}
	vec = mainChain;
}

// FORD JOHNSON (vector)
void	PmergeMe::sortDeque(std::deque<int> &deq)
{
	size_t n = deq.size();
	if (n <= 1)
		return;

	// pairs (large, small)
	std::deque<std::pair<int, int> > pairs;
	int orphan = -1;
	bool hasOrphan = (n % 2 != 0);

	for (size_t i = 0; i < n - (hasOrphan ? 1 : 0); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	if (hasOrphan)
		orphan = deq[n - 1];

	// Extract mainChain (large)
	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
	}

	// recursive sort for mainChain
	sortDeque(mainChain);

	// sort "small" to match with large order
	std::deque<int> pend;
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (mainChain[i] == pairs[j].first)
			{
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}

	// insert the first small (associated with first large)
	if (!pend.empty())
	{
		mainChain.push_front(pend[0]);
	}

	// insert other elem with Jacobsthal
	std::vector<size_t> jacob = generateJacobsthalSequence(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	if (!pend.empty())
		inserted[0] = true; //small 1 alrdy insert

	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t index = jacob[i] - 1;
		if (index < pend.size() && !inserted[index])
		{
			std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[index]);
			mainChain.insert(it, pend[index]);
			inserted[index] = true;

			for (size_t j = index - 1; j > 0; --j)
			{
				if (!inserted[j])
				{
					it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j]);
					mainChain.insert(it, pend[j]);
					inserted[j] = true;
				}
			}
		}
	}

	//insert elem remains that overflows suite
	for (size_t i = 1; i < pend.size(); ++i)
	{
		if (!inserted[i])
		{
			std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
			mainChain.insert(it, pend[i]);
		}
	}

	//insert orphan if one
	if (hasOrphan)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), orphan);
		mainChain.insert(it, orphan);
	}
	deq = mainChain;
}

void	PmergeMe::execute()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < this->_vec.size(); i++)
	{
		std::cout << this->_vec[i] << (i + 1 < this->_vec.size() ? " " : "");
	}
	std::cout << std::endl;

	clock_t startVec = clock();
	sortVector(this->_vec);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	clock_t startDeq = clock();
	sortDeque(this->_deq);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After: ";
	for (size_t i = 0; i < this->_vec.size(); ++i)
	{
		std::cout << this->_vec[i] << (i + 1 < this->_vec.size() ? " " : "");
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vec.size()
				<< " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deq.size()
				<< " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
