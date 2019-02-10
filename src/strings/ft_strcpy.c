/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:12:38 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:23:51 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strcpy(const char *dst, const char *src)
{
	dst = ft_memcpy((void*)dst, src, ft_strlen(src) + 1);
	((char*)dst)[ft_strlen(src)] = 0;
	return ((char*)dst);
}
