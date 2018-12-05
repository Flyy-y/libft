/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:14:46 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/15 16:26:37 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	if (ft_strlen(src) >= n)
		return (ft_memcpy(dst, src, n));
	else
	{
		ft_memcpy(dst, src, n);
		ft_memset(dst + ft_strlen(src), 0, n - ft_strlen(src));
	}
	return (dst);
}
