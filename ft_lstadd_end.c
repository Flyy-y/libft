/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:21:35 by cbreisch          #+#    #+#             */
/*   Updated: 2018/11/16 18:00:08 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	while ((*alst)->next)
		(*alst) = (*alst)->next;
	(*alst)->next = new;
}
