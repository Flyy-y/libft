/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:18:37 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:49:21 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	i = -1;
	if (n <= 0 || dst == src)
		return (dst);
	while (++i < (long)n)
		((char*)dst)[i] = ((char*)src)[i];
	return (dst);
}
