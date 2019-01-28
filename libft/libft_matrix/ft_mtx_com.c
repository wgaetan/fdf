/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_com.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 21:47:30 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 12:19:41 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

t_mtx	*ft_mtx_com(t_mtx mtx)
{
	t_mtx	*tmp;
	t_mtx	*minor;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tmp = (t_mtx *)malloc(sizeof(t_mtx));
	ft_mtx_build(tmp, mtx.m, mtx.n, 0);
	while (++i < mtx.m)
	{
		while (++j < mtx.n)
		{
			minor = ft_mtx_minor(mtx, i, j);
			tmp->data[i][j] = ((i + j) % 2 ? -1 : 1)
			* ft_mtx_det(*minor);
			ft_mtx_destroy(minor);
		}
		j = -1;
	}
	return (tmp);
}
