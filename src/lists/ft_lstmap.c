/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:24:24 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:51:41 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"
#include "ft_mem.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!f || !lst)
		return ((t_list*)0);
	if (!(new = (t_list*)ft_memalloc(sizeof(t_list))))
		return (t_list*)0;
	new = f(lst);
	if (lst->next)
	{
		new->next = ft_lstmap(lst->next, f);
		if (!(new->next))
		{
			free(new);
			return ((t_list*)0);
		}
	}
	else
		new->next = (t_list*)0;
	return (new);
}
