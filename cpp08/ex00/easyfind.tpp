/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:24:54 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 15:26:42 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	// search with find
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	// value doesnt exist
	if (it == container.end())
	{
		throw NotFoundException();
	}

	return it;
}