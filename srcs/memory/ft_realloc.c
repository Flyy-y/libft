/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:36:18 by cbreisch          #+#    #+#             */
/*   Updated: 2019/01/15 16:54:36 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t old_size, size_t new_size)
{
	void*	new;

	new = NULL;
	if (new_size == 0)
	{
		free(p);
		return (NULL);
	}
	else if (!p)
		return (ft_memalloc(new_size));
	else if (new_size > old_size)
	{
		new = ft_memalloc(new_size);
		if (new)
		{
			ft_memcpy(new, p, old_size);
			free(p);
		}
		return (new);
	}
	return (new);
}
