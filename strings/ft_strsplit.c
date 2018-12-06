/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:49:08 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:29:47 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	strsplit_count(char const *s, char c)
{
	t_bool	new_string;
	size_t	count;

	new_string = TRUE;
	count = 0;
	while (s && *s++)
	{
		if (*s && *s == c)
			new_string = TRUE;
		else if (*s && new_string)
		{
			count++;
			new_string = FALSE;
		}
	}
	return (count);
}

static size_t	*strsplit_string_sizes(char const *s, char c, long *x)
{
	size_t	count;
	size_t	*sizes;
	long	i;

	count = strsplit_count(s, c);
	if (!(sizes = (size_t*)ft_memalloc(sizeof(size_t) * (count + 1))))
		return ((size_t*)0);
	i = (-1L);
	while ((size_t)++i < count)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			sizes[i]++;
		}
	}
	*x = (-1L);
	return (sizes);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	*sizes;
	char	**split;
	long	i;
	long	j;

	sizes = strsplit_string_sizes(s, c, &i);
	if (!(split = ft_memalloc(sizeof(char*) * (strsplit_count(s, c) + 1))))
		return ((char**)0);
	while (sizes && sizes[++i])
		if (!(split[i] = ft_memalloc(sizeof(char) * (sizes[i] + 1))))
			return ((char**)0);
	i = (-1L);
	while (sizes && sizes[++i])
	{
		j = (-1L);
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			split[i][++j] = *s;
			s++;
		}
	}
	free(sizes);
	return (split);
}
