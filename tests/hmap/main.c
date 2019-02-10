/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:41:17 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 04:22:02 by cbreisch         ###   ########.fr       */
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
		i++;
	}
	key.id = count / 2;
	ft_hmap_delitem(m, ft_hmap_getitem(m, key));
	key.id = 0;
	ft_hmap_delitem(m, ft_hmap_getitem(m, key));
	key.id = count - 1;
	ft_hmap_delitem(m, ft_hmap_getitem(m, key));

	ft_hashmap_clear(m);
	ft_hashmap_clear(ch);
	return (0);
}