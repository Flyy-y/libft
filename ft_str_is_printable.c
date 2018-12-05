/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:41:31 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/15 17:37:59 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_printable(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
		if (!ft_isprint(*s))
			return (FALSE);
		else
			s++;
	return (TRUE);
}
