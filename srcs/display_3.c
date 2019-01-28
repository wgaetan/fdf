/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_3.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 14:08:48 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 16:49:25 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_disp_h3(t_mem *mem)
{
	t_affvars	var;
	int			i;
	int			j;

	i = mem->nb_y - 1;
	while (i >= 0)
	{
		j = mem->nb_x - 1;
		while (j > 0)
		{
			var.cx = -mem->pt_grid[i][j].data[0] * mem->zoom + mem->x_offset;
			var.cy = -mem->pt_grid[i][j].data[1] * mem->zoom + mem->y_offset;
			var.dx = -mem->pt_grid[i][j - 1].data[0] *
			mem->zoom + mem->x_offset;
			var.dy = -mem->pt_grid[i][j - 1].data[1] *
			mem->zoom + mem->y_offset;
			var.color1 = mem->pt_grid[i][j].color;
			var.color2 = mem->pt_grid[i][j - 1].color;
			if (ft_optimize(var, mem))
				bresenham_gen(mem, var);
			j--;
		}
		i--;
	}
}

void	ft_disp_v3(t_mem *mem)
{
	t_affvars	var;
	int			i;
	int			j;

	i = mem->nb_y - 1;
	while (i > 0)
	{
		j = mem->nb_x - 1;
		while (j >= 0)
		{
			var.cx = -mem->pt_grid[i][j].data[0] * mem->zoom + mem->x_offset;
			var.cy = -mem->pt_grid[i][j].data[1] * mem->zoom + mem->y_offset;
			var.dx = -mem->pt_grid[i - 1][j].data[0] *
			mem->zoom + mem->x_offset;
			var.dy = -mem->pt_grid[i - 1][j].data[1] *
			mem->zoom + mem->y_offset;
			var.color1 = mem->pt_grid[i][j].color;
			var.color2 = mem->pt_grid[i - 1][j].color;
			if (ft_optimize(var, mem))
				bresenham_gen(mem, var);
			j--;
		}
		i--;
	}
}
