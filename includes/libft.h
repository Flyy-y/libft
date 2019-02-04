/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbreisch <cbreisch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:33:15 by cbreisch          #+#    #+#             */
/*   Updated: 2019/02/04 17:25:24 by cbreisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFF_SIZE 64
# define MAX_FD 32
# define HMAP_FF 16

typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0
}				t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef union	u_hkey
{
	char	*str;
	long	id;
}				t_hkey;

typedef	struct	s_hitem
{
	t_hkey			key;
	void			*value;
	unsigned long	hash;
	size_t			val_size;
	struct s_hitem	*next;
}				t_hitem;

typedef	struct	s_hmap
{
	int				length;
	unsigned long	(*hash_func)(const void *str, size_t len);
	t_bool			use_id_as_key;
	t_hitem			*fast_forward;
	t_hitem			*items;
}				t_hmap;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(const char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memdup(const void *str, size_t len);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(wchar_t c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(long n);
void			ft_putchar_fd(wchar_t c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(long n, int fd);

t_list			*ft_lstnew(void	const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstfind(t_list *lst, void *to_find,
					t_bool (*f)(t_list *lst, void *to_find));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_lstlen(t_list *lst);

char			*ft_strrev(char *str);

void			**ft_memalloc_2d(size_t len_x, size_t len_y,
	size_t size_x, size_t size_y);
void			ft_memdel_2d(void **p, size_t n);
void			ft_lstadd_end(t_list **alst, t_list *new);
long			ft_pow(long n, long pow);
char			*ft_strcapitalize(char *s);

t_bool			ft_str_is_alpha(const char *s);
t_bool			ft_str_is_lowercase(const char *s);
t_bool			ft_str_is_numeric(const char *s);
t_bool			ft_str_is_printable(const char *s);
t_bool			ft_str_is_uppercase(const char *s);
size_t			ft_strnlen(const char *str, size_t max);
void			*ft_realloc(void *p, size_t old_size, size_t new_size);
size_t  		ft_sqrt_up(size_t n);

int				get_next_line(const int fd, char **line);

t_hitem			*ft_hmap_additem(t_hmap *m, char *key, void *val, size_t val_size);
t_hmap			*ft_hmap_init(t_bool id_as_key);

#endif
