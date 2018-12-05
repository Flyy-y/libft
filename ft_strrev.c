/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:17:09 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/10 17:22:31 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	long	i;
	size_t	length;
	char	buffer;

	length = ft_strlen(str);
	i = (-1L);
	while ((size_t)++i < (length / 2))
	{
		buffer = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = buffer;
	}
	return (str);
}
