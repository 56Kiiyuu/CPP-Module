/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:43:48 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 15:57:10 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{}

Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{}

Span &Span::operator=(const Span &rhs) 
{
	if (this != &rhs) 
	{
		this->_maxSize = rhs._maxSize;
		this->_numbers = rhs._numbers;
	}
	return *this;
}

Span::~Span() 
{}

void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_maxSize)
	{
		throw SpanFullException();
	}
	this->_numbers.push_back(number);
}

int	Span::longestSpan()
{
	if (this->_numbers.size() < 2)
	{
		throw NoSpanException();
	}
	int minVal = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int maxVal = *std::max_element(this->_numbers.begin(), this->_numbers.end());

	return maxVal - minVal;
}

int	Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
	{
		throw NoSpanException();
	}
	// copy vector in order to not modify original order
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minSpan)
		{
			minSpan = diff;
		}
	}
	return minSpan;
}