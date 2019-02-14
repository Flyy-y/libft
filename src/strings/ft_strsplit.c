/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:49:08 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/14 19:28:50 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

static char		*ft_replace_chr(char const *s, char c_1, char c_2)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c_1)
			*((char *)s + i) = c_2;
		++i;
	}
	return ((char *)s);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		end;
	char	tmp[ft_strlen(s) + 1];
	char	**arr;

	i = 0;
	j = 0;
	end = ft_strlen(s);
	ft_bzero(tmp, sizeof(tmp));
	ft_strcpy(tmp, s);
	ft_replace_chr(tmp, c, '\0');
	arr = (char **)ft_memalloc(sizeof(*arr) * (end));
	while (i < end && s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		arr[j] = ft_strdup(tmp + i);
		++j;
		while (tmp[i] != '\0')
			++i;
		++i;
	}
	arr[j] = 0;
	return (arr);
}
