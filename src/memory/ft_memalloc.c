/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:00:11 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/28 14:27:47 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	while (size % (__WORDSIZE / 8))
		size++;
	if (!(ptr = malloc(size)))
		return ((void*)0);
	ft_bzero(ptr, size);
	return (ptr);
}
