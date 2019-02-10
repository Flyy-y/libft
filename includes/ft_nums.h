/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:21:21 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:48:02 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMS_H
# define FT_NUMS_H

# include "ft_types.h"

long	ft_atol(const char *str);
char	*ft_ltoa(long n);
long	ft_max(long a, long b);
long	ft_min(long a, long b);
long	ft_pow(long n, long pow);
long	ft_sqrt_up(long n);

#endif
