/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 15:38:34 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 21:22:15 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/libft_matrix/libft_matrix.h"

# define COLOR_1_R 255
# define COLOR_1_G 255
# define COLOR_1_B 255
# define COLOR_1_A 0


# define COLOR_2_R 0
# define COLOR_2_G 150
# define COLOR_2_B 200
# define COLOR_2_A 0
/*
** functions
*/

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef struct		s_pt
{
	float			data[3];
	t_color			color;
}					t_pt;

typedef struct		s_affvars
{
	int				cx;
	int				dx;
	int				cy;
	int				dy;
	float			z;
	int				p1 : 4;
	int				p2 : 4;
	t_color			color1;
	t_color			color2;
}					t_affvars;

typedef struct		s_bresvar
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	float			i;
}					t_bresvar;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_win
{
	void			*win_ptr;
	int				width;
	int				height;
}					t_win;

typedef struct		s_mem
{
	t_color			color[100];
	t_color			color1;
	t_color			color2;
	t_win			win;
	t_img			img;
	t_img			bck;
	int				max_z;
	int				min_z;
	float			theta;
	float			alpha;
	void			*mlx_ptr;
	t_pt			**pt_grid;
	float			**tab;
	int				nb_x;
	int				nb_y;
	int				x_offset;
	int				y_offset;
	int				zoom;
}					t_mem;

int					ft_key(int key, t_mem *mem);
void				ft_main_loop(t_mem *mem);
void				color_init(t_mem *mem);
void				parse(t_mem *map, char *file);
void				ft_get_pt_grid(t_mem *mem);
void				ft_matrix_compute(t_mem *mem);
void				ft_mtx_display(t_mem *mem);
void				bresenham_gen(t_mem *mem, t_affvars var);
void				ft_put_pixel(t_mem *mem, t_color color, int x, int y);
void				display(t_mem *mem);
void				ft_create_img(t_mem *mem);
t_color				pt_color(t_mem *mem, int i, int j);
t_color				ft_color_calc(t_affvars var);
void				ft_disp_h0(t_mem *mem);
void				ft_disp_v0(t_mem *mem);
void				ft_disp_h1(t_mem *mem);
void				ft_disp_v1(t_mem *mem);
void				ft_disp_h2(t_mem *mem);
void				ft_disp_v2(t_mem *mem);
void				ft_disp_h3(t_mem *mem);
void				ft_disp_v3(t_mem *mem);
int					ft_optimize(t_affvars var, t_mem *mem);
void				ft_create_xpm_img(void *mlx_ptr, t_img *img, char *str);
void				ft_init_backgrounds(t_mem *mem);
int					ft_error_map(t_mem *mem, int i);
void				free_tab(t_mem *mem);
void				free_ptgrid(t_mem *mem);
void				ft_free_err2(t_mem *mem);

/*
** keyboard touch value
*/

# define TOUCH_1 18
# define TOUCH_2 19
# define TOUCH_3 20
# define TOUCH_4 21
# define TOUCH_5 23
# define TOUCH_6 22
# define TOUCH_7 26
# define TOUCH_8 28
# define TOUCH_9 25
# define TOUCH_0 29
# define TOUCH_Q 12
# define TOUCH_W 13
# define TOUCH_E 14
# define TOUCH_R 15
# define TOUCH_T 17
# define TOUCH_Y 16
# define TOUCH_A 0
# define TOUCH_S 1
# define TOUCH_D 2
# define TOUCH_F 3
# define TOUCH_G 5
# define TOUCH_Z 6
# define TOUCH_X 7
# define TOUCH_C 8
# define TOUCH_V 9
# define TOUCH_B 11
# define TOUCH_ECHAP 53
# define TOUCH_ENTER 36
# define TOUCH_LEFT 123
# define TOUCH_RIGHT 124
# define TOUCH_DOWN 125
# define TOUCH_UP 126
# define TOUCH_NUMPAD_0 82
# define TOUCH_NUMPAD_1 83
# define TOUCH_NUMPAD_2 84
# define TOUCH_NUMPAD_3 85
# define TOUCH_NUMPAD_4 86
# define TOUCH_NUMPAD_5 87
# define TOUCH_NUMPAD_6 88
# define TOUCH_NUMPAD_7 89
# define TOUCH_NUMPAD_8 91
# define TOUCH_NUMPAD_9 92
# define TOUCH_NUMPAD_POINT 65
# define TOUCH_NUMPAD_ENTER 76
# define TOUCH_NUMPAD_PLUS 69
# define TOUCH_NUMPAD_LESS 78
# define TOUCH_NUMPAD_TIMES 67
# define TOUCH_NUMPAD_DIVIDE 75
# define TOUCH_NUMPAD_NUM 71
# define TOUCH_NUMPAD_INSERT 114
# define TOUCH_NUMPAD_END 119
# define TOUCH_NUMPAD_DELL 117
# define TOUCH_NUMPAD_PAGEUP 116
# define TOUCH_NUMPAD_PAGEDOWN 121
# define TOUCH_NUMPAD_HOME 115

#endif
