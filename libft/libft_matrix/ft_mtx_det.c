/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_det.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 21:49:01 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 12:08:51 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

float	ft_mtx_det(t_mtx m)
{
	int		i;
	float	det;
	t_mtx	*tmp;

	i = -1;
	det = 0;
	if (m.m != m.n || m.n < 2 || m.m < 2)
		return (-1);
	if (m.m == 2)
		return ((m.data[0][0] * m.data[1][1]) - (m.data[0][1] * m.data[1][0]));
	while (++i < m.m)
	{
		tmp = ft_mtx_minor(m, i, 0);
		det += m.data[i][0] * (float)((i) % 2 ? -1 : 1)
		* ft_mtx_det(*tmp);
		ft_mtx_destroy(tmp);
	}
	return (det);
}
