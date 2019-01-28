/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_times_scal.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 22:31:42 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 11:18:24 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

t_mtx		*ft_mtx_times_scal(t_mtx mtx, double scalar)
{
	t_mtx	*prod;
	int		i;
	int		j;

	i = 0;
	j = 0;
	prod = (t_mtx *)malloc(sizeof(t_mtx));
	ft_mtx_build(prod, mtx.m, mtx.n, 0);
	while (i < mtx.m)
	{
		while (j < mtx.n)
		{
			prod->data[i][j] = mtx.data[i][j] * scalar;
			j++;
		}
		j = 0;
		i++;
	}
	return (prod);
}
