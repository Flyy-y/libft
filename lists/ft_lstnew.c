/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:47:49 by cbreisch          #+#    #+#             */
/*   Updated: 2018/12/06 18:29:47 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
