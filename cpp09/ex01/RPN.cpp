/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:47:40 by kevlim            #+#    #+#             */
/*   Updated: 2026/09/04 13:24:24 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &src) : _stack(src._stack)
{}

RPN	&RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return *this;
}

RPN::~RPN()
{}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPN::executeOperation(char op)
{
	if (this->_stack.size() < 2)
		return false;

	//LIFO
	int b = this->_stack.top();
	this->_stack.pop();
	int a = this->_stack.top();
	this->_stack.pop();

	switch (op)
	{
	case '+':
		this->_stack.push(a + b);
		break;
	case '-':
		this->_stack.push(a - b);
		break;
	case '*':
		this->_stack.push(a * b);
		break;
	case '/':
		if (b == 0)
			return false;
		this->_stack.push(a / b);
		break;
	default:
		return false;
	}
	return true;
}

bool	RPN::evaluate(const std::string &expression)
{
	// clean stack for sure
	while (!this->_stack.empty())
		this->_stack.pop();

	for (size_t i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];
		if (std::isspace(c))
			continue;
		if (std::isdigit(c))
		{
			this->_stack.push(c - '0');
		}
		else if (isOperator(c))
		{
			if (!executeOperation(c))
				return false;
		}
		else
		{
			return false;
		}
	}
	if (this->_stack.size() != 1)
		return false;
	std::cout << this->_stack.top() << std::endl;
	return true;
}
