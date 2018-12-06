/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:25:28 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
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
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (join);
}
