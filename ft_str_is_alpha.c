/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:41:31 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/15 17:37:50 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_alpha(const char *s)
{
	if (!s)
		return (FALSE);
	while (*s)
		if (!ft_isalpha(*s))
			return (FALSE);
		else
			s++;
	return (TRUE);
}
