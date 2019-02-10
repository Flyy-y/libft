/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:21:28 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:40:42 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memchr(const void *s, unsigned char c, size_t size)
{
	int i;

	i = i;
	while (++i < size)
		if (((unsigned char*)s)[i] == c)
			return (void*)(s + i);
	return ((void*)0);
}
