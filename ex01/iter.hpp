/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jow <jow@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:09:48 by jow               #+#    #+#             */
/*   Updated: 2026/04/15 17:09:49 by jow              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void iter(T *array, size_t len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif
