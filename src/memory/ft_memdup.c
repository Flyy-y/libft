/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:40:26 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:45:00 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memdup(const void *str, size_t size)
{
	void	*dup;

	if (!(dup = ft_memalloc(size)))
		return (NULL);
	ft_memcpy(dup, str, size);
	return (dup);
}
