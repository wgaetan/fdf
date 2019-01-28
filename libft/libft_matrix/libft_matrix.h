/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft_matrix.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 21:54:09 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 13:11:47 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_MATRIX_H
# define LIBFT_MATRIX_H

# include <stdlib.h>
# include <math.h>

typedef struct		s_mtx
{
	float			**data;
	int				m : 3;
	int				n : 3;
}					t_mtx;

void				ft_mtx_build(t_mtx *mtx, int m, int n, int value);
t_mtx				*ft_mtx_com(t_mtx mtx);
float				ft_mtx_det(t_mtx m);
t_mtx				*ft_mtx_minor(t_mtx m, int y, int x);
t_mtx				*ft_mtx_times_mtx(t_mtx m1, t_mtx m2);
t_mtx				*ft_mtx_times_scal(t_mtx mtx, double scalar);
t_mtx				*ft_mtx_trans(t_mtx mtx);
void				ft_mtx_destroy(t_mtx *mtx);

#endif
