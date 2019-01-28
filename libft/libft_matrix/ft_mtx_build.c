/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_build.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 21:52:08 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 11:19:29 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

void	ft_mtx_build(t_mtx *mtx, int m, int n, int value)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	mtx->m = m > 15 ? 15 : m;
	mtx->m = m < 0 ? 0 : m;
	mtx->n = n > 15 ? 15 : n;
	mtx->n = n < 0 ? 0 : n;
	mtx->data = (float **)malloc(sizeof(float *) * m);
	while (++i < mtx->m)
	{
		mtx->data[i] = (float *)malloc(sizeof(float) * n);
		while (++j < mtx->n)
			mtx->data[i][j] = value;
		j = -1;
	}
}
