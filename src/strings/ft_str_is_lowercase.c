/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:41:31 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:22:33 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

t_bool	ft_str_is_lowercase(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
		if (!ft_islower(*s))
			return (FALSE);
		else
			s++;
	return (TRUE);
}
