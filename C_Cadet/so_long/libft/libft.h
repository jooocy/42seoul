/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:46:37 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/25 21:16:52 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int				ft_atoi(const char *str);
void			*ft_bzero(void *dest, size_t count);
int				ft_isalnum(int a);
int				ft_isalpha(int a);
int				ft_isascii(int c);
int				ft_isdigit(int a);
int				ft_isprint(int a);
void			*ft_memmove(void *dest, const void *src, size_t count);
void			*ft_memcpy(void *dest, const void *src, size_t count);
void			*ft_memset(void *dest, int ch, size_t count);
char			*ft_strrchr(const char *str, int to_find);
char			*ft_strdup(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *a1, const char *a2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
const void		*ft_memchr(const void *buf, int c, size_t count);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *str, int to_find);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));


#endif