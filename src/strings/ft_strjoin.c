/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:25:28 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:25:27 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;

	if (!s1 || !s2)
		return ((char*)0);
	if (!(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return ((char*)0);
	if (!ft_strcat(join, s1))
		return ((char*)0);
	if (!ft_strcat(join, s2))
		return ((char*)0);
	return (join);
}
