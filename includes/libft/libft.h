/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:59:45 by bruno             #+#    #+#             */
/*   Updated: 2019/11/19 11:02:45 by cbruno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

# define BUFF_SIZE 32
# ifdef OPEN_MAX_
#  define OPEN_MAX _SC_OPEN_MAX
# endif

/*
** Structures
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Part 1 - Fonctions de la libc
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Part 2 - Fonctions supplementaires
*/

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
void				ft_putstr(char const *c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Partie bonus
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Ajouts personnels
*/

char				*ft_realloc(char *oldbuffer, size_t buffersize);
char				*ft_strtolow(char *str);
char				*ft_capitalize(char *str);
long				ft_digitnb(int n);
int					ft_countwords(char const *str, char c);
t_list				*ft_lst_reverse(t_list *alst);
void				ft_lst_addback(t_list **alst, t_list *new);
int					ft_nbofwords(char *s, char c);
int					get_next_line(int fd, char **line);
char				**ft_split_whitespace(char *str);
void				ft_printtab(char **tab);

/*
** Vecteur 1x3
*/

void				get_vector(float vect[3], float x, float y, float z);
void				vector_init(float dest[3], float x, float y, float z);
void				vector_cpy(float dest[3], float src[3]);
void				vector_normalize(float vect[3]);
void				vector_scale(float vect[3], float scale);
void				vector_cross(float dest[3], float a[3], float b[3]);
void				vector_transform(float dest[3], float matrix[4][4],
									float src[3]);
void				vector_diff(float dest[3], float from[3], float to[3]);
void				vector_add(float dest[3], float src[3]);

/*
** Matrix 4x4
*/

void				matrix_unit(float matrix[4][4]);
void				matrix_transpose(float dest[4][4], float src[4][4]);
void				matrix_multi(float dest[4][4], float a[4][4],
								float b[4][4]);
void				get_rotate_x(float dst[4][4], float angle);
void				get_rotate_y(float dst[4][4], float angle);
void				get_rotate_z(float dst[4][4], float angle);
#endif
