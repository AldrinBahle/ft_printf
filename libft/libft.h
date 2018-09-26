/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 10:55:41 by agama             #+#    #+#             */
/*   Updated: 2018/08/03 08:21:56 by agama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t num_bts);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void	*dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t dest_size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ***************** Additional Functions ***************************************
*/

void				ft_atoi_add_digit_u(const char c, unsigned int *number);
void				ft_putnbr_large_fd(intmax_t number, int file_descriptor);
int					ft_count_digits_ularge(uintmax_t number);
intmax_t			ft_abs_large(intmax_t number);
void				ft_itoa_write(char *last_digit, uintmax_t number);
void				ft_putstrn_fd(char const *source, size_t max_length
								, int file_descriptor);
size_t				ft_wstrlen(const wchar_t *source);
void				ft_putcharn(char c, size_t number);
void				ft_putcharn_fd(char c, size_t number, int file_descriptor);
void				ft_putstr_lateral_fd(char const *source, int file_descriptor);
size_t				ft_count_chars(const char *haystack, char needle, size_t length);
char				*ft_itoa_large(intmax_t number);
char				*ft_itoa_ularge(uintmax_t number);
char				*ft_base_itoa(uintmax_t number, int base);
void				ft_putstr_lateral_fd(const char *source, int file_descriptor);
void				ft_strtolower(char *str);

#endif
