/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:53:56 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:24:37 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	if (!(dup = ft_strnew(ft_strlen(src))))
		return ((void*)0);
	return (ft_memcpy(dup, src, ft_strlen(src)));
}
