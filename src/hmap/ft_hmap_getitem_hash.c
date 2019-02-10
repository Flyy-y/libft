/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_getitem_hash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 09:21:29 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 09:43:24 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"

t_hitem	*ft_hmap_getitem_hash(t_hmap *m, unsigned long hash)
{
	t_hitem	*curr;

	curr = m->items;
	if (!m || !m->length)
		return (NULL);
	while (curr)
		if (curr->hash == hash)
			return (curr);
		else
			curr = curr->next;
	return (NULL);
}
