/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:55:17 by cbreisch          #+#    #+#             */
/*   Updated: 2019/01/17 00:16:01 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel_2d(void ***p)
{
	size_t y;

	y = -1;
	while ((*p)[++y])
		ft_memdel((*p)[y]);
	ft_memdel((*p)[y]);
	ft_memdel(*p);
}