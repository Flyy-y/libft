/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:15:41 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 03:12:17 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHARTESTS_H
# define FT_CHARTESTS_H

#include "ft_types.h"

t_bool	ft_isalnum(unsigned char c);
t_bool	ft_isalpha(unsigned char c);
t_bool	ft_isascii(unsigned char c);
t_bool	ft_isblank(unsigned char c);
t_bool	ft_iscntrl(unsigned char c);
t_bool	ft_isdigit(unsigned char c);
t_bool	ft_isgraph(unsigned char c);
t_bool	ft_islower(unsigned char c);
t_bool	ft_isprint(unsigned char c);
t_bool	ft_isspace(unsigned char c);
t_bool	ft_isupper(unsigned char c);
t_bool	ft_isxdigit(unsigned char c);

unsigned char	ft_tolower(unsigned char c);
unsigned char	ft_toupper(unsigned char c);

#endif
