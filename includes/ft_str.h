/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:22:15 by cbreisch          #+#    #+#             */
/*   Updated: 2019/05/23 14:36:58 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include "ft_types.h"
# include "ft_chartests.h"
# include "unistd.h"

t_bool	ft_str_is_alpha(const char *s);
t_bool	ft_str_is_lowercase(const char *s);
t_bool	ft_str_is_numeric(const char *s);
t_bool	ft_str_is_printable(const char *s);
t_bool	ft_str_is_uppercase(const char *s);

char	*ft_strcapitalize(char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strchri(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(const char *dst, const char *src);
char	*ft_strdup(const char *src);
int		ft_strequ(char const *s1, char const *s2);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
int		ft_strnlen(const char *str, int max);
char	*ft_strnstr(char const *s1, char const *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str);
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
size_t	ft_wcharlen(unsigned int wc);
size_t	ft_wstrlen(unsigned int *s);

#endif
