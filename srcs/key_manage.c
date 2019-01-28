/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_manage.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/06 15:06:54 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 21:13:31 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	mod_z(t_mem *mem, int f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < mem->nb_y)
	{
		j = 0;
		while (j < mem->nb_x)
		{
			if (f == 2)
				mem->tab[i][j] *= -1;
			if (f == 1)
				mem->tab[i][j] *= 2;
			if (f == 0)
				mem->tab[i][j] /= 2;
			j++;
		}
		i++;
	}
}

static void	key_manage2(t_mem *mem, int key)
{
	if (key == TOUCH_W)
	{
		mem->alpha += 1;
		if (mem->alpha < -16)
			mem->alpha += 32;
		if (mem->alpha > 16)
			mem->alpha -= 32;
	}
	if (key == TOUCH_G)
		mod_z(mem, 2);
	if (key == TOUCH_ECHAP)
	{
		mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
		free_ptgrid(mem);
		free_tab(mem);
		free(mem);
		exit(1);
	}
}

static void	key_manage(t_mem *mem, int key)
{
	if (key == TOUCH_A)
	{
		mem->theta -= 1;
		if (mem->theta < -16)
			mem->theta += 32;
		if (mem->theta > 16)
			mem->theta -= 32;
	}
	if (key == TOUCH_S)
	{
		mem->theta += 1;
		if (mem->theta < -16)
			mem->theta += 32;
		if (mem->theta > 16)
			mem->theta -= 32;
	}
	if (key == TOUCH_Q)
	{
		mem->alpha -= 1;
		if (mem->alpha < -16)
			mem->alpha += 32;
		if (mem->alpha > 16)
			mem->alpha -= 32;
	}
	key_manage2(mem, key);
}

/*static void	ft_back_keys(int key, t_mem *mem)
{
	if (key == TOUCH_NUMPAD_TIMES)
		mem->backid++;
	if (key == TOUCH_NUMPAD_DIVIDE)
		mem->backid--;
	if (mem->backid > 11)
		mem->backid = 0;
	if (mem->backid < 0)
		mem->backid = 11;
}*/

int			ft_key(int key, t_mem *mem)
{
	if (key == TOUCH_NUMPAD_LESS && mem->zoom > 1)
		mem->zoom /= 2;
	if (key == TOUCH_NUMPAD_PLUS)
		mem->zoom *= 2;
	if (key == TOUCH_RIGHT)
		mem->x_offset += 100;
	if (key == TOUCH_NUMPAD_4)
		mod_z(mem, 0);
	if (key == TOUCH_NUMPAD_5)
		mod_z(mem, 1);
	if (key == TOUCH_LEFT)
		mem->x_offset -= 100;
	if (key == TOUCH_UP)
		mem->y_offset -= 100;
	if (key == TOUCH_DOWN)
		mem->y_offset += 100;
	key_manage(mem, key);
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_create_img(mem);
	ft_main_loop(mem);
	return (0);
}
