/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:01:56 by cbreisch          #+#    #+#             */
/*   Updated: 2019/01/25 19:08:46 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_memalloc_2d(size_t len_x, size_t len_y,
	size_t size_x, size_t size_y)
{
	void	**array;
	size_t	i;

	if (!(array = ft_memalloc(size_x * (len_x + 1))))
		return (NULL);
	i = -1;
	while (++i < len_x)
		if (!(array[i] = ft_memalloc(size_y * (len_y + 1))))
			return (NULL);
	return (array);
}
