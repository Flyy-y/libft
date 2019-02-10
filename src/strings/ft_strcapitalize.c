/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:01:15 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:34:08 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_chartests.h"

char *ft_strcapitalize(char *str)
{
	int		i;
	t_bool	upper;

	i = 0;
	upper = TRUE;
	while (str[i] != 0)
	{
		if (ft_isalnum(str[i]))
		{
			if (upper && ft_islower(str[i]))
				str[i] = ft_toupper(str[i]);
			else if (!upper && ft_isupper(ft_isupper(str[i])))
				str[i] = ft_tolower(str[i]);
			upper = FALSE;
		}
		else
			upper = TRUE;
		i++;
	}
	return (str);
}