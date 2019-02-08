/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_additem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:08:51 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/08 02:43:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

static t_bool	regen_ff(t_hmap *m)
{
	int		i;
	t_hitem	*item;

	if (m->ff)
		free(m->ff);
	if (!(m->ff = ft_memalloc(sizeof(t_hitem*) * ((m->length + 1) / HMAP_FF))))
		return (FALSE);
	i = 0;
	item = m->items;
	while (item)
	{
		if (i == 0 || i % HMAP_FF == 0)
			m->ff[i / HMAP_FF] = item;
		item = item->next;
		i++;
	}
	return (TRUE);
}

static t_hitem	*prepare_item(t_hmap *m, char *key, void *val, size_t val_size)
{
	t_hitem *i;
	t_hkey	hkey;

	if (m->use_id_as_key)
		hkey.id = m->length;
	else if (key == NULL || !(hkey.str = ft_strdup(key)))
		return (NULL);
	if (!(i = ft_memalloc(sizeof(t_hitem))))
	{
		if (m->use_id_as_key)
			free(hkey.str);
		return (NULL);
	}
	i->key = hkey;
	i->val_size = val_size;
	if (i->val_size && !(i->value = ft_memdup(val, val_size)))
		return (NULL);
	else if (!i->val_size)
		i->value = NULL;
	i->hash = m->hash_func(i->value, i->val_size);
	return (i);
}

t_hitem			*ft_hmap_additem(t_hmap *m, char *key, void *val,
					size_t val_size)
{
	t_hitem	*tmp;
	t_hitem	*i;

	if (!(i = prepare_item(m, key, val, val_size)))
		return (NULL);
	if (m->length > 0)
	{
		tmp = m->items;
		while (tmp->next)
			tmp = tmp->next;
		i->prev = tmp;
		tmp->next = i;
	}
	else
	{
		m->items = i;
		i->prev = NULL;
	}
	m->length++;
	if (m->use_id_as_key && ((m->length - 1) % HMAP_FF) == 0)
		if (!regen_ff(m))
			return (NULL);
	return (i);
}
