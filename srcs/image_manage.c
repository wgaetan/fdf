/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image_manage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 15:27:19 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 22:08:38 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_create_img(t_mem *mem)
{
	mem->img.ptr = mlx_new_image(mem->mlx_ptr, mem->win.width, mem->win.height);
	mem->img.data = mlx_get_data_addr(mem->img.ptr, &mem->img.bpp,
		&mem->img.sizeline, &mem->img.endian);
}

void	ft_put_pixel(t_mem *mem, t_color color, int x, int y)
{
	int				bpp;

	bpp = mem->img.bpp / 8;
	if ((x > 0 && x < mem->win.width) && (y > 0 && y < mem->win.height))
	{
		mem->img.data[(x * bpp) + (mem->img.sizeline * y)] = color.b;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 1] = color.g;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 2] = color.r;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 3] = color.a;
	}
}

void	ft_create_xpm_img(void *mlx_ptr, t_img *img, char *str)
{
	int		i;
	int		j;

	i = 1800;
	j = 900;
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, str, &i, &j);
	img->data = mlx_get_data_addr(img->ptr, &img->bpp,
		&img->sizeline, &img->endian);
}
