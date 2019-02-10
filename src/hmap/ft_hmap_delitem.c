/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_delitem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:20:29 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:57:43 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_mem.h"

void	ft_hmap_delitem(t_hmap *m, t_hitem *item)
{
	if (!item)
		return ;
	if (item->prev)
		item->prev->next = item->next;
	else
		m->items = item->next;
	if (item->next)
		item->next->prev = item->prev;
	if (!(m->use_id_as_key))
		free(item->key.str);
	if (item->val_size)
		free(item->value);
	free(item);
	m->length--;
}
