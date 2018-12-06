/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:59:36 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	long counter;

	counter = (-1L);
	if (n <= 0 || dst == src)
		return ((void*)0);
	while (++counter < (long)n)
	{
		((char *)dst)[counter] = ((char *)src)[counter];
		if (((unsigned char*)src)[counter] == (unsigned char)c)
			return (void*)(dst + counter + 1);
	}
	return ((void*)0);
}
