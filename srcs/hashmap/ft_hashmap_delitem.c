/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashmap_delitem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:20:29 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/04 19:29:52 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	ft_hmap_delitem(t_hmap *m, t_hkey k)
{
	t_hitem	*item;

	if (!(item = ft_hmap_getitem(m, k)))
		return ;
	if (m->use_id_as_key)
		free(item->key.str);
	if (item->val_size)
		free(item->value);
	free(item);
}