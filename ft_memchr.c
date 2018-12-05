/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:21:28 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/16 19:54:03 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	long i;

	i = (-1L);
	while (++i < (long)n)
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return (void*)(s + i);
	return ((void*)0);
}
