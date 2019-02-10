/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:30:40 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:33:13 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	long	len;
	long	start;

	if (!s)
		return ((char*)0);
	len = ft_strlen(s);
	start = (-1L);
	while (s[len - 1] && (ft_isblank(s[len - 1]) || s[len - 1] == '\n'))
		len--;
	while (s[++start] && (ft_isblank(s[start]) || s[start] == '\n'))
		len--;
	if (len <= 0)
		return (ft_strdup(""));
	if (!(trimmed = ft_strnew(len)))
		return ((char*)0);
	return (ft_strsub(s, start, len));
}
