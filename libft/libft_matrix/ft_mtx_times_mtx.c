/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_times_mtx.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 21:52:36 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 11:20:27 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

t_mtx	*ft_mtx_times_mtx(t_mtx m1, t_mtx m2)
{
	t_mtx	*prod;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = -1;
	if (m1.n != m2.m)
		return (NULL);
	prod = (t_mtx *)malloc(sizeof(t_mtx));
	ft_mtx_build(prod, m1.m, m2.n, 0);
	while (++i < prod->m)
	{
		while (j < prod->n)
		{
			while (++k < m1.n)
				prod->data[i][j] += m1.data[i][k] * m2.data[k][j];
			k = -1;
			j++;
		}
		j = 0;
		k = -1;
	}
	return (prod);
}
