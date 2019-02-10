/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:18:17 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:51:38 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include "ft_types.h"
# include "stdlib.h"
# include "stdint.h"

void	ft_bzero(void *s, size_t size);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t size);
void	*ft_memchr(const void *s, unsigned char c, size_t size);
int		ft_memcmp(const void *str1, const void *str2, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memdup(const void *str, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
void	*ft_memset(void *s, int c, size_t size);



#endif
