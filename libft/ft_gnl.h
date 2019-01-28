/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gnl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 19:31:53 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 18:22:10 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# define BUFF_SIZE 1000
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct s_var	t_var;

struct	s_var {
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	char	*endl;
	int		i;
	int		r_state;
};

typedef struct s_fd	t_fd;

struct	s_fd {
	char	*save;
	int		fd;
	int		eof;
	t_fd	*next;
};

int		ft_gnl(const int fd, char **line);
#endif
