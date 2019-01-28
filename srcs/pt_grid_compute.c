/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pt_grid_compute.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/01 15:46:48 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:41:43 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static void	pt_time_mtx(t_pt *pt, float *mtx)
{
	float	tmp[3];
	int		i;
	int		j;

	tmp[0] = 0;
	tmp[1] = 0;
	tmp[2] = 0;
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			tmp[i] += pt->data[j] * mtx[i + j * 3];
			j++;
		}
		j = 0;
		i++;
	}
	pt->data[0] = tmp[0];
	pt->data[1] = tmp[1];
	pt->data[2] = tmp[2];
}

static void	pt_grid_compute(t_mem *mem, float *mtx)
{
	int		i;
	int		j;

	i = 0;
	while (i < mem->nb_y)
	{
		j = 0;
		while (j < mem->nb_x)
		{
			mem->pt_grid[i][j].data[0] = (float)j - ((float)mem->nb_x / 2.0);
			mem->pt_grid[i][j].data[1] = (float)i - ((float)mem->nb_y / 2.0);
			mem->pt_grid[i][j].data[2] = (float)mem->tab[i][j];
			pt_time_mtx(&mem->pt_grid[i][j], mtx);
			j++;
		}
		i++;
	}
}

static void	ft_init_mtx(t_mem *mem, float *mtx)
{
	mtx[0] = cos(mem->theta * (M_PI_4 / 4) + M_PI_2);
	mtx[1] = sin(mem->theta * (M_PI_4 / 4) + M_PI_2);
	mtx[2] = 0;
	mtx[6] = -(cos(mem->alpha * (M_PI_4 / 4)) * cos(mem->theta
		* (M_PI_4 / 4)));
	mtx[7] = -(cos(mem->alpha * (M_PI_4 / 4)) * sin(mem->theta
		* (M_PI_4 / 4)));
	mtx[8] = -(sin(mem->alpha * (M_PI_4 / 4)));
	mtx[3] = (mtx[1] * mtx[8]) - (mtx[2]
			* mtx[7]);
	mtx[4] = (mtx[2] * mtx[6]) - (mtx[0]
			* mtx[8]);
	mtx[5] = (mtx[0] * mtx[7]) - (mtx[1]
			* mtx[6]);
}

void		ft_inv(float *mtx, float *mtx2)
{
	float	det;

	det = mtx[0] * (mtx[4] * mtx[8] - mtx[5] * mtx[7]);
	det -= mtx[1] * (mtx[3] * mtx[8] - mtx[5] * mtx[6]);
	det += mtx[2] * (mtx[3] * mtx[7] - mtx[4] * mtx[6]);
	mtx2[0] = mtx[4] * mtx[8] - mtx[7] * mtx[5];
	mtx2[3] = -(mtx[3] * mtx[8] - mtx[6] * mtx[5]);
	mtx2[6] = mtx[3] * mtx[7] - mtx[6] * mtx[4];
	mtx2[1] = -(mtx[1] * mtx[8] - mtx[7] * mtx[2]);
	mtx2[4] = mtx[0] * mtx[8] - mtx[6] * mtx[2];
	mtx2[7] = -(mtx[0] * mtx[7] - mtx[6] * mtx[1]);
	mtx2[2] = mtx[1] * mtx[5] - mtx[4] * mtx[2];
	mtx2[5] = -(mtx[0] * mtx[5] - mtx[3] * mtx[2]);
	mtx2[8] = mtx[0] * mtx[4] - mtx[1] * mtx[3];
	det = 1.0 / det;
	mtx[0] = mtx2[0] * det;
	mtx[1] = mtx2[1] * det;
	mtx[2] = mtx2[2] * det;
	mtx[3] = mtx2[3] * det;
	mtx[4] = mtx2[4] * det;
	mtx[5] = mtx2[5] * det;
	mtx[6] = mtx2[6] * det;
	mtx[7] = mtx2[7] * det;
	mtx[8] = mtx2[8] * det;
}

void		ft_matrix_compute(t_mem *mem)
{
	float	*mtx;
	float	*mtx2;

	if (!(mtx = (float *)malloc(sizeof(float) * 9)))
		exit(0);
	if (!(mtx2 = (float *)malloc(sizeof(float) * 9)))
		exit(0);
	ft_init_mtx(mem, mtx);
	ft_inv(mtx, mtx2);
	pt_grid_compute(mem, mtx);
	free(mtx);
	free(mtx2);
}
