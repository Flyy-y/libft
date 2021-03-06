/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:47:49 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 02:51:51 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lists.h"
#include "ft_mem.h"

t_list	*ft_lstnew(void const *c, size_t c_size)
{
	t_list	*lst;

	if (!(lst = ft_memalloc(sizeof(t_list))))
		return ((t_list*)0);
	if (c)
	{
		if (!(lst->content = ft_memalloc(c_size)))
		{
			free(lst);
			return ((t_list*)0);
		}
		lst->content = ft_memcpy(lst->content, c, c_size);
		lst->content_size = c_size;
	}
	else
	{
		lst->content = (void*)0;
		lst->content_size = 0UL;
	}
	lst->next = (t_list*)0;
	return (lst);
}
