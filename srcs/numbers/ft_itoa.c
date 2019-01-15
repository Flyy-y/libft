/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:38:47 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:36:07 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	buff[20];
	long	counter;
	t_bool	neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_bzero(&buff, 20);
	counter = 0L;
	if (n == 0)
		return (ft_strdup("0"));
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
