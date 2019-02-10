/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:41:31 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:04:16 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chartests.h"
#include "ft_nums.h"

long	ft_atol(const char *str)
{
	unsigned long	result;
	t_bool			negative;
	unsigned int	i;

	i = 0;
	result = 0;
	negative = FALSE;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
		negative = TRUE;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-result);
	return (result);
}
