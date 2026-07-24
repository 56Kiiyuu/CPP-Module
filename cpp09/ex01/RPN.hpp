/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 14:42:26 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/24 14:45:42 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>

class RPN
{
private:
	std::stack<int>	_stack;
	bool	isOperator(char c) const;
	bool	executeOperation(char op);
public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &rhs);
	~RPN();

	bool	evaluate(const std::string &expression);
};

#endif

