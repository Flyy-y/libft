/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:05:17 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:55:49 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	long	i;
	char	*sub;

	i = (-1L);
	if (!s || start > (unsigned int)ft_strlen(s))
		return ((char*)0);
	if (!(sub = ft_strnew(len)))
		return ((char*)0);
	while ((size_t)++i < len && s[i + start])
		sub[i] = s[i + start];
	sub[i] = 0;
	return (sub);
}
