/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:07:24 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 01:33:30 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"

t_list	*ft_lstfind(t_list *lst, void *to_find,
	t_bool (*f)(t_list *lst, void *to_find))
{
	if (!f)
		return ((t_list*)0);
	while (lst)
		if (f(lst, to_find))
			return (lst);
		else
			lst = lst->next;
	return ((t_list*)0);
}
