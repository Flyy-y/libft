/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_additem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:08:51 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/04 17:33:56 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_hitem	*prepare_item(t_hmap *m, char *key, void *val, size_t val_size)
{
	t_hitem *i;
	t_hkey	hkey;

	if (m->use_id_as_key)
		hkey.id = m->length;
	else
		if (key == NULL)
			return (NULL);
		else
			if (!(hkey.str = ft_strdup(key)))
				return (NULL);
	if (!(i = ft_memalloc(sizeof(t_hitem))))
	{
		free(hkey.str);
		return (NULL);
	}
	i->key = hkey;
	i->val_size = val_size;
	if (i->val_size)
	{
		if (!(i->value = ft_memdup(val, val_size)))
			return (NULL);
	}
	else
		i->value = NULL;
	i->hash = m->hash_func(i->value, i->val_size);
	return (i);
}

t_hitem			*ft_hmap_additem(t_hmap *m, char *key, void *val, size_t val_size)
{
	t_hitem	*tmp;
	t_hitem	*i;

	if (!(i = prepare_item(m, key, val, val_size)))
		return NULL;
	if (m->length > 0)
	{
		tmp = m->items;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = i;
	}
	else
		m->items = i;
	m->length++;
	return (i);
}