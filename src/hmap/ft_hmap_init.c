/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:08:51 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/14 19:24:21 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_mem.h"

static unsigned long	hash(const void *str, size_t len)
{
	unsigned long hash;
	unsigned long i;

	hash = 0;
	i = 0;
	while (i < len)
	{
		hash += ((unsigned char*)str)[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 4);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

t_hmap					*ft_hmap_init(t_bool id_as_key)
{
	t_hmap	*m;

	if (!(m = ft_memalloc(sizeof(t_hmap))))
		return (NULL);
	m->length = 0;
	m->use_id_as_key = id_as_key;
	m->ff = NULL;
	m->hash_func = &hash;
	return (m);
}
