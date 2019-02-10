/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 02:18:58 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:51:20 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stdint.h>

void	*ft_memset(void *s, int c, size_t size)
{
    uintptr_t *p;
    uintptr_t x;
    int i;

	p = (uintptr_t*)s;
	x = c & 0xff;
    i = 2;
	while ((1 << ++i) < __WORDSIZE)
        x |= x << (1<<i);
    size >>= i-3;
    while (size--)
        *p++ = x;
    return (s);
}
