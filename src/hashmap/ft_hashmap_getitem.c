/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_getitem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:25:02 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/08 00:33:55 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_hitem	*ft_hmap_getitem(t_hmap *m, t_hkey k)
{
	size_t	cur_id;
	t_hitem	*cur_item;

	cur_id = 0;
	cur_item = NULL;
	cur_item = m->items;
	if (m->use_id_as_key && k.id < m->length)
	{
		if (k.id > HMAP_FF)
			cur_item = m->fast_forward[k.id / HMAP_FF];			
		while (cur_item->key.id < k.id)
			cur_item = cur_item->next;
	}
	else if (m->length > 0)
		while (cur_id != m->length && ft_strcmp(cur_item->key.str, k.str))
		{
			cur_id++;
			cur_item = cur_item->next;
		}
	return (cur_item);
}
