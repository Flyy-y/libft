/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:41:17 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/28 14:53:14 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	char	*x = "weopkekopekopfekpfwekopfwekopfewokpkfowep";
	t_hkey	key;
	t_hmap	*m;
	t_hmap	*ch;
	int		count;
	int		i;
	unsigned long hash;

	if (argc != 2)
		exit (1);
	
	count = ft_atol(argv[1]);
	if (!(m = ft_hmap_init(TRUE)) || !(ch = ft_hmap_init(FALSE)))
		return (1);
	i = 0;
	while (i < count)
	{
		ft_hmap_additem(m, NULL, x, 42);
		ft_hmap_additem(ch, "superkey", x, 42);
		hash = ch->items->hash;
		i++;
	}
	i = 0;
	while (++i < count)
	{
		key.id = i;
		ft_hmap_getitem(m, key);
		ft_hmap_getitem_hash(ch, hash);
	}
	while (++i < count)
	{
		key.id = i;
		m->use_ff = FALSE;
		ft_hmap_delitem(m, ft_hmap_getitem(m, key));
		ft_hmap_delitem(ch, ft_hmap_getitem_hash(ch, hash));
	}
	ft_hashmap_clear(m);
	ft_hashmap_clear(ch);
	return (0);
}
