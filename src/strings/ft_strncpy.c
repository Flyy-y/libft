/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:14:46 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:45:59 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	if ((size_t)ft_strlen(src) >= n)
		return (ft_memcpy(dst, src, n));
	else
	{
		ft_memcpy(dst, src, n);
		ft_memset(dst + ft_strlen(src), 0, n - ft_strlen(src));
	}
	return (dst);
}
