/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mtx_destroy.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/28 22:24:54 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/05 13:11:48 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft_matrix.h"

void	ft_mtx_destroy(t_mtx *mtx)
{
	int		i;

	i = -1;
	while (++i < mtx->m)
		free(mtx->data[i]);
	free(mtx->data);
}
