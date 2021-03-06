/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:11:03 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:45:29 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_c;
	unsigned char *src_c;

	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	if (dst > src)
		while (len--)
			dst_c[len] = src_c[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
