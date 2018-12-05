/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:43:24 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/15 17:37:00 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	unsigned char	**mem;

	if (ap)
	{
		mem = (unsigned char**)ap;
		free((void*)*mem);
		*ap = (void*)0;
	}
}
