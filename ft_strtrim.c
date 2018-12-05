/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:30:40 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/15 17:20:42 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
