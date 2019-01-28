/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 18:57:49 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:49:55 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft_matrix/libft_matrix.h"
# include "ft_gnl.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_gnl(const int fd, char **line);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest, void *src, size_t n);
void				ft_putchar(char c);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(char *str);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char *str, char c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
void				ft_putstr(char *str);

#endif
