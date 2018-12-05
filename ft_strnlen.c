/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:50:03 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/16 20:45:42 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, size_t max)
{
	char *start;

	start = (char*)str + 1;
	while (*str++ && (size_t)(str - start) < max)
		;
	return ((size_t)(str - start));
}
