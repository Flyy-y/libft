/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:53:56 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/16 21:43:08 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	if (!(dup = ft_strnew(ft_strlen(src))))
		return ((void*)0);
	return (ft_memcpy(dup, src, ft_strlen(src)));
}
