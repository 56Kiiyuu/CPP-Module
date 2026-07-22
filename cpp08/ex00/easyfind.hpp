/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:18:20 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 15:25:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <exception>
# include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not found in container!";
		}
};

# include "easyfind.tpp"
#endif