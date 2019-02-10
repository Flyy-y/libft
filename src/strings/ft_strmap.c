/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:57:29 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:27:16 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	i = -1;
	if (!s || !f || !(new = ft_strnew(ft_strlen(s))))
		return ((char*)0);
	while (s[++i])
		new[i] = f(s[i]);
	return (new);
}
