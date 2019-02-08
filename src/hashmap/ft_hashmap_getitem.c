/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_getitem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:25:02 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/08 01:24:41 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

static t_bool	compare_hkeys(t_hmap *m, t_hkey k1, t_hkey k2)
{
	if (m->use_id_as_key)
		return (k1.id == k2.id);
	else
		return (ft_strcmp(k1.str, k2.str) == 0);
}

t_hitem	*ft_hmap_getitem(t_hmap *m, t_hkey k)
{
	size_t	cur_id;
	t_hitem	*cur_item;

	cur_id = 0;
	cur_item = m->items;
	if (!m || !m->length)
		return (NULL);
	if (m->use_id_as_key &&k.id > HMAP_FF)
	{
		cur_item = m->ff[k.id / HMAP_FF];
		cur_id = k.id * HMAP_FF;
	}
	while (cur_id < m->length && !compare_hkeys(m, cur_item->key, k))
	{
		cur_item = cur_item->next;
		cur_id++;
	}
	if (cur_item && compare_hkeys(m, k, cur_item->key))
		return (cur_item);
	else
		return (NULL);
}
