/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:58:32 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/16 21:32:57 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	long	i;

	i = (-1L);
	if (!n)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strnlen(s1, n) != ft_strnlen(s2, n))
		return (0);
	while (++i < ((long)n - 1))
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
