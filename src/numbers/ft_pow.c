/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:31:29 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:09:20 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pow(long n, long pow)
{
	long res;

	res = n;
	while (pow > 0)
	{
		res *= n;
		pow--;
	}
	return (res);
}
