/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:42:55 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/17 12:15:44 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_sqrt(int nb);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int n);
char				*ft_strrchr(const char *str, int n);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strend(const char *s1, const char *s2, size_t start);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putnbr(int n);
void				ft_bzero(void *s, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_numberlength(int n);
char				**ft_mktab(char const *s, char c);
int					ft_replace_char(char *s, char c, char n);
void				ft_strcapitalize(char *s);
void				ft_swap(char *a, char *b);
char				*ft_strrev(char *s);
void				ft_print_tab(char **tab);
char				**ft_tabrev(char **s);
char				*ft_strjoin_free(char *s1, char *s2);
int					fill_line(char **line, char **stock);
int					get_next_line(int fd, char **line);
int					ft_error(char *str, int fd);
void				print_tab(char **tab);
double				ft_abs(double i);
float				ft_power(float x, int n);

#endif
