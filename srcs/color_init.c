/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color_init.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 18:44:03 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 17:15:01 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_init(t_mem *mem)
{
	int		i;
	float	r;
	float	g;
	float	b;

	i = 0;
	r = (mem->color2.r - mem->color1.r);
	g = (mem->color2.g - mem->color1.g);
	b = (mem->color2.b - mem->color1.b);
	while (i < 100)
	{
		mem->color[i].r = mem->color1.r + (i * r);
		mem->color[i].g = mem->color1.r + (i * g);
		mem->color[i].b = mem->color1.r + (i * b);
		i++;
	}
}
