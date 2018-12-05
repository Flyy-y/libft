/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:01:08 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/16 21:38:53 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	len;

	if (!*s2)
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1 && n >= len)
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return ((char*)0);
}
