/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:13:30 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*valid;
	long	i;

	if (ft_strlen(s) == 0 && c == 0)
		return (void*)(s);
	valid = 0;
	i = (-1L);
	while ((size_t)++i != ft_strlen(s))
		if (ft_strchr(s + i, c))
			valid = ft_strchr(s + i, c);
	return (valid);
}
