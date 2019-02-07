/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:41:17 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/07 23:55:47 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hashmap.h"

int	main(int argc, char **argv)
{
	t_hkey	k;
	char	*x = "randomodwopwqdokpwdqkopwdqstring";
	t_hmap	*id;
	t_hmap	*ch;
	int		count;
	int		i;

	if (argc != 2)
		exit (1);
	
	count = ft_atoi(argv[1]);
	id = ft_hmap_init(TRUE);
	ch = ft_hmap_init(FALSE);
	i = 0;
	while (i < count)
	{
		ft_hmap_additem(id, NULL, x, 33);
		ft_hmap_additem(ch, &(x[i]), x, 33);
		i++;
	}
	i = 0;
	{
		k.id = i;
		ft_hmap_delitem(id, k);
		k.str = &(x[i]);
		ft_hmap_delitem(ch, k);
		i++;
	}
	return (0);
}