/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:52:59 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:59:40 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hmap.h"
#include "ft_mem.h"

void	ft_hashmap_clear(t_hmap *map)
{
	while (map->items)
		ft_hmap_delitem(map, map->items);
	if (map->ff)
		free(map->ff);
	free(map);
}
