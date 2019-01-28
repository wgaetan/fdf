/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color_manage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:26:02 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:15:22 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	pt_color(t_mem *mem, int i, int j)
{
	double	z;
	t_color	color;

	if ((mem->max_z - mem->min_z) != 0)
	{
		z = (mem->tab[i][j] - mem->min_z);
		z /= (mem->max_z - mem->min_z);
		color.r = mem->color1.r + z * (mem->color2.r - mem->color1.r);
		color.g = mem->color1.g + z * (mem->color2.g - mem->color1.g);
		color.b = mem->color1.b + z * (mem->color2.b - mem->color1.b);
		color.a = 0;
		return (color);
	}
	else
		return (mem->color1);
}

t_color	ft_color_calc(t_affvars var)
{
	t_color new;

	new.r = (var.color2.r - var.color1.r) * var.z;
	new.r += var.color1.r;
	new.g = (var.color2.g - var.color1.g) * var.z;
	new.g += var.color1.g;
	new.b = (var.color2.b - var.color1.b) * var.z;
	new.b += var.color1.b;
	new.a = 0;
	return (new);
}
