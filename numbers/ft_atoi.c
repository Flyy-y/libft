/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:41:31 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:29:47 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	result;
	t_bool			negative;
	unsigned int	i;

	i = 0;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
		(str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		++i;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-result);
	else
		return (result);
}
