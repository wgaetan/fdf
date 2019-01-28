/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 18:00:30 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:13:49 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_init_bvar(t_bresvar *bvar, t_affvars var)
{
	bvar->dx = abs(var.dx - var.cx);
	bvar->dy = abs(var.dy - var.cy);
	bvar->sx = (var.cx < var.dx ? 1 : -1);
	bvar->sy = (var.cy < var.dy ? 1 : -1);
	bvar->err = (bvar->dx > bvar->dy ? bvar->dx : -bvar->dy) / 2;
}

static float	bresenham_calc(t_affvars var)
{
	t_bresvar	bvar;

	ft_init_bvar(&bvar, var);
	bvar.i = 0;
	while (1)
	{
		bvar.i++;
		if (var.cx == var.dx && var.cy == var.dy)
			break ;
		bvar.e2 = bvar.err;
		if (bvar.e2 > -bvar.dx)
		{
			bvar.err -= bvar.dy;
			var.cx += bvar.sx;
		}
		if (bvar.e2 < bvar.dy)
		{
			bvar.err += bvar.dx;
			var.cy += bvar.sy;
		}
	}
	return (bvar.i);
}

void			bresenham_gen(t_mem *mem, t_affvars var)
{
	t_bresvar	bvar;
	int			j;

	ft_init_bvar(&bvar, var);
	bvar.i = bresenham_calc(var);
	j = 0;
	while (1)
	{
		var.z = ((1 / bvar.i) * j);
		ft_put_pixel(mem, ft_color_calc(var), var.cx, var.cy);
		if (var.cx == var.dx && var.cy == var.dy)
			break ;
		bvar.e2 = bvar.err;
		if (bvar.e2 > -bvar.dx)
		{
			bvar.err -= bvar.dy;
			var.cx += bvar.sx;
		}
		if (bvar.e2 < bvar.dy)
		{
			bvar.err += bvar.dx;
			var.cy += bvar.sy;
		}
		j++;
	}
}
