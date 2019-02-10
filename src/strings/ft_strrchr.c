/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:13:30 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:54:18 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*valid;
	long	i;

	if (ft_strlen(s) == 0 && c == 0)
		return (void*)(s);
	valid = 0;
	i = (-1L);
	while (++i != ft_strlen(s))
		if (ft_strchr(s + i, c))
			valid = ft_strchr(s + i, c);
	return (valid);
}
