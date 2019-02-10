/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:16:05 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/10 04:10:29 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>

# define BUFF_SIZE 64
# define MAX_FD 32

void	ft_putchar_fd(int c, int fd);
void	ft_putchar(int c);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr(long n);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
int		get_next_line(const int fd, char **line);

#endif
