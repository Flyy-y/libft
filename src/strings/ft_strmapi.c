/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:00:26 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:27:22 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long	i;
	char	*new;

	i = (-1L);
	if (!s || !f || !(new = ft_strnew(ft_strlen(s))))
		return ((char*)0);
	while (s[++i])
		new[i] = f((unsigned int)i, s[i]);
	return (new);
}
