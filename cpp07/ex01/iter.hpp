/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:00:17 by kevlim            #+#    #+#             */
/*   Updated: 2026/07/22 14:06:11 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>

template <typename T, typename F>
void iter(T *array, const std::size_t length, F function)
{
	if (!array || !function)
	{
		return;
	}
	for (std::size_t i = 0; i < length; ++i)
	{
		function(array[i]);
	}
}

#endif