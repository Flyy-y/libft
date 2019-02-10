/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:38:47 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:13:45 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nums.h"
#include "ft_mem.h"
#include "ft_str.h"

char		*ft_ltoa(long n)
{
	char	buff[20];
	long	counter;
	t_bool	neg;

	ft_bzero(&buff, 20);
	counter = 0L;
	if (n == 0)
		return ("0");
	if (TRUE == (neg = (t_bool)(n < 0)))
		n = -n;
	while (n > 0)
	{
		buff[counter++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		buff[counter++] = '-';
	ft_strrev(buff);
	return (ft_strdup(buff));
}
