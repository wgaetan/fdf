/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 13:37:40 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 18:29:52 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_optimize(t_affvars var, t_mem *mem)
{
	var.p1 = 0;
	var.p2 = 0;
	if (var.cx < 0)
		var.p1 += 8;
	else if (var.cx > mem->win.width)
		var.p1 += 4;
	if (var.cy < 0)
		var.p1 += 2;
	else if (var.cy > mem->win.height)
		var.p1 += 1;
	if (var.dx < 0)
		var.p1 += 8;
	else if (var.dx > mem->win.width)
		var.p1 += 4;
	if (var.dy < 0)
		var.p1 += 2;
	else if (var.dy > mem->win.height)
		var.p1 += 1;
	if (var.p1 != 0 && var.p2 != 0)
		if ((var.p1 & var.p2) != 0)
			return (0);
	return (1);
}

int		calc_start(t_mem *mem)
{
	int		i;
	int		a;

	a = mem->pt_grid[0][0].data[2];
	i = 0;
	if (mem->pt_grid[0][mem->nb_x - 1].data[2] > a)
	{
		a = mem->pt_grid[0][mem->nb_x - 1].data[2];
		i = 1;
	}
	if (mem->pt_grid[mem->nb_y - 1][0].data[2] > a)
	{
		a = mem->pt_grid[mem->nb_y - 1][0].data[2];
		i = 2;
	}
	if (mem->pt_grid[mem->nb_y - 1][mem->nb_x - 1].data[2] > a)
	{
		a = mem->pt_grid[mem->nb_y - 1][mem->nb_x - 1].data[2];
		i = 3;
	}
	return (i);
}

void	display(t_mem *mem)
{
	int		start;

	start = calc_start(mem);
	if (start == 0)
	{
		ft_disp_v0(mem);
		ft_disp_h0(mem);
	}
	else if (start == 1)
	{
		ft_disp_v1(mem);
		ft_disp_h1(mem);
	}
	else if (start == 2)
	{
		ft_disp_v2(mem);
		ft_disp_h2(mem);
	}
	else if (start == 3)
	{
		ft_disp_v3(mem);
		ft_disp_h3(mem);
	}
}
