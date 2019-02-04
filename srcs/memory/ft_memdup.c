/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:40:26 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/04 15:42:59 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *str, size_t len)
{
	void	*dup;

	if (!(dup = ft_memalloc(len)))
		return (NULL);
	ft_memcpy(dup, str, len);
	return (dup);
}