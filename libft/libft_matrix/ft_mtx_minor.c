/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_minor.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 21:49:42 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 09:55:11 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

t_mtx	*ft_mtx_minor(t_mtx m, int y, int x)
{
	t_mtx	*tmp;
	int		i;
	int		j;
	int		a;
	int		b;

	i = 0;
	a = 0;
	b = 0;
	j = 0;
	tmp = (t_mtx *)malloc(sizeof(t_mtx));
	ft_mtx_build(tmp, m.m - 1, m.n - 1, 0);
	while ((a == y ? ++a : a) < m.m)
	{
		while ((b == x ? ++b : b) < m.n)
			tmp->data[i][j++] = m.data[a][b++];
		j = 0;
		b = 0;
		a++;
		i++;
	}
	return (tmp);
}
