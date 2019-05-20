/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:22:57 by cbreisch          #+#    #+#             */
/*   Updated: 2019/05/20 13:28:53 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

int	ft_strchri(const char *s, int c)
{
	return (int)((char*)ft_memchr(s, c, ft_strlen(s) + 1) - s);
}
