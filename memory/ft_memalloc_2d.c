/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:01:56 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc_2d(size_t x, size_t y, size_t content_size)
{
	void	**array;
	size_t	i;

	if (!(array = ft_memalloc(sizeof(void*) * (x + 1))))
		return ((void**)0);
	i = 0;
	while (i++ < x)
		if (!(array[i] = ft_memalloc(content_size * (y + 1))))
			return ((void*)0);
	return (array);
}
