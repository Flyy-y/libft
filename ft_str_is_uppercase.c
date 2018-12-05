/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:41:31 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/15 17:38:02 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_uppercase(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
		if (!ft_isupper(*s))
			return (FALSE);
		else
			s++;
	return (TRUE);
}
