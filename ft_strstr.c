/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:01:08 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/10 17:27:33 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char *p;

	p = (char*)s1;
	if (!ft_strlen(s2))
		return (p);
	while ((p = ft_strchr(p, *s2)))
	{
		if (ft_strncmp(p, s2, ft_strlen(s2)) == 0)
			return (char*)p;
		p++;
	}
	return ((char*)0);
}
