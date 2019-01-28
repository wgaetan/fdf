/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:57:16 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 21:22:01 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_fill_image(t_mem *mem)
{
	int		i;
	int		j;
	t_color	color;

	i = 0;
	j = 0;
	color.r = 0;
	color.g = 0;
	color.g = 0;
	color.a = 255;
	while (i < 900)
	{
		while (j < 1800)
		{
			ft_put_pixel(mem, color, j, i);
			j++;
		}
		j = 0;
		i++;
	}
}

static int	ft_init(t_mem *mem)
{
	mem->color1.r = COLOR_1_R;
	mem->color1.g = COLOR_1_G;
	mem->color1.b = COLOR_1_B;
	mem->color1.a = COLOR_1_A;
	mem->color2.r = COLOR_2_R;
	mem->color2.g = COLOR_2_G;
	mem->color2.b = COLOR_2_B;
	mem->color2.a = COLOR_2_A;
	mem->theta = 4;
	mem->alpha = 4;
	mem->win.width = 1800;
	mem->win.height = 900;
	mem->zoom = 10;
	mem->x_offset = mem->win.width / 2;
	mem->y_offset = mem->win.height / 2;
	mem->mlx_ptr = mlx_init();
	mem->win.win_ptr = mlx_new_window(mem->mlx_ptr, mem->win.width,
			mem->win.height, "fdf");
	ft_create_img(mem);
	mem->bck.ptr = mlx_new_image(mem->mlx_ptr, mem->win.width, mem->win.height);
	mem->bck.data = mlx_get_data_addr(mem->img.ptr, &mem->img.bpp,
		&mem->img.sizeline, &mem->img.endian);
	return (1);
}

int			ft_error_map(t_mem *mem, int i)
{
	if (i == 0)
		ft_putstr("Usage fdf: ./fdf [maps.fdf]\n");
	if (i == 1)
		ft_putstr("No data found.\n");
	if (i == 2)
	{
		ft_free_err2(mem);
		ft_putstr("Found wrong line length. Exiting.\n");
	}
	free(mem);
	exit(0);
}

void		ft_main_loop(t_mem *mem)
{
	ft_matrix_compute(mem);
	ft_fill_image(mem);
	display(mem);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->bck.ptr, 0, 0);
	mlx_put_image_to_window(mem->mlx_ptr, mem->win.win_ptr, mem->img.ptr, 0, 0);
}

int			main(int ac, char **av)
{
	t_mem	*mem;
	int		j;
	int		i;

	if (!(mem = (t_mem *)malloc(sizeof(t_mem))))
		exit(0);
	if (ac != 2)
		ft_error_map(mem, 0);
	i = -1;
	parse(mem, av[1]);
	ft_init(mem);
	if (!(mem->pt_grid = (t_pt **)malloc(sizeof(t_pt *) * mem->nb_y)))
		exit(0);
	while (++i < mem->nb_y)
	{
		j = -1;
		if (!(mem->pt_grid[i] = (t_pt *)malloc(sizeof(t_pt) * mem->nb_x)))
			exit(0);
		while (++j < mem->nb_x)
			mem->pt_grid[i][j].color = pt_color(mem, i, j);
	}
	ft_main_loop(mem);
	mlx_key_hook(mem->win.win_ptr, ft_key, mem);
	mlx_loop(mem->mlx_ptr);
	return (1);
}
