/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:08:51 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/04 19:24:37 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

static unsigned long	sdbm(const void *str, size_t len)
{
	unsigned long	hash;
	unsigned char	*c;
	unsigned int	i;

	i = 0;
	c = (unsigned char*)str;
	while (i < len)
	{
		hash = (unsigned long)(c + (hash << 6) + (hash << 16) - hash);
		i++;
		c++;
	}
	return (hash);
}

t_hmap					*ft_hmap_init(t_bool id_as_key)
{
	t_hmap	*m;

	if (!(m = ft_memalloc(sizeof(t_hmap))))
		return (NULL);
	m->length = 0;
	m->use_id_as_key = id_as_key;
	m->fast_forward = NULL;
	m->hash_func = &sdbm;
	return (m);
}
