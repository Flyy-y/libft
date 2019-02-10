/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:59:36 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:41:15 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t size)
{
	int	i;

	i = -1;
	if (size <= 0 || dst == src)
		return ((void*)0);
	while (++i < size)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return (void*)(dst + i + 1);
	}
	return ((void*)0);
}
