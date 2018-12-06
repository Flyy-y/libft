/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:01:15 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	long	i;
	t_bool	new_word;

	i = -1;
	new_word = TRUE;
	while (s[++i])
	{
		if (ft_islower(s[i]) && new_word)
			s[i] -= 32;
		if (ft_isalnum(s[i]))
			new_word = FALSE;
		else
			new_word = TRUE;
		i++;
	}
	return (s);
}
