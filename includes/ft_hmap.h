/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:33:15 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 09:26:00 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HMAP_H
# define FT_HMAP_H

# include "ft_types.h"
# include "unistd.h"

# define HMAP_FF 16UL

typedef union	u_hkey
{
	char			*str;
	unsigned long	id;
}				t_hkey;

typedef	struct	s_hitem
{
	t_hkey			key;
	void			*value;
	unsigned long	hash;
	size_t			val_size;
	struct s_hitem	*next;
	struct s_hitem	*prev;
}				t_hitem;

typedef	struct	s_hmap
{
	size_t			length;
	unsigned long	(*hash_func)(const void *str, size_t len);
	t_bool			use_id_as_key;
	t_hitem			**ff;
	t_hitem			*items;
}				t_hmap;

t_hitem			*ft_hmap_additem(t_hmap *m, char *key, void *val,
					size_t val_size);
t_hmap			*ft_hmap_init(t_bool id_as_key);
t_hitem			*ft_hmap_getitem(t_hmap *m, t_hkey k);
t_hitem			*ft_hmap_getitem_hash(t_hmap *m, unsigned long hash);
void			ft_hmap_delitem(t_hmap *m, t_hitem *item);
void			ft_hashmap_clear(t_hmap *map);

#endif
