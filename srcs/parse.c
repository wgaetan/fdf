/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 17:34:25 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 15:14:27 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		free_split(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static float	*fill_tab_2(t_mem *map, float *tab, int a, char **split_space)
{
	int			i;

	i = 0;
	while (split_space[i])
	{
		tab[i] = (float)ft_atoi(split_space[i]);
		if (a == 0 && i == 0)
		{
			map->min_z = tab[i];
			map->max_z = tab[i];
		}
		if (tab[i] < map->min_z)
			map->min_z = tab[i];
		else if (tab[i] > map->max_z)
			map->max_z = tab[i];
		i++;
	}
	return (tab);
}

static float	*fill_tab(char *split, t_mem *map, int size, int a)
{
	int		i;
	char	**split_space;
	float	*tab;

	i = 0;
	split_space = ft_strsplit(split, ' ');
	while (split_space[i])
		i++;
	if ((map->nb_x != 0 && map->nb_x != i))
		ft_error_map(map, 2);
	map->nb_x = i;
	if (!(tab = (float *)malloc(sizeof(int) * i + 1)))
		exit(0);
	tab = fill_tab_2(map, tab, a, split_space);
	map->nb_y = size;
	map->tab[size] = 0;
	free_split(split_space);
	return (tab);
}

static void		parse2(t_mem *map, char **split, int i)
{
	int		a;

	a = 0;
	if (i == 0)
		ft_error_map(map, 1);
	if (!(map->tab = (float **)malloc(sizeof(int *) * i + 1)))
		exit(0);
	while (a < i)
	{
		map->tab[a] = fill_tab(split[a], map, i, a);
		a++;
	}
	free_split(split);
}

void			parse(t_mem *map, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	*tmp;
	char	**split;

	i = 0;
	if ((fd = open(file, O_RDWR)) < 0)
		ft_error_map(map, 1);
	file = ft_strdup("");
	while (ft_gnl(fd, &line))
	{
		tmp = file;
		file = ft_strjoin(file, line);
		free(line);
		free(tmp);
		tmp = file;
		file = ft_strjoin(file, " |");
		free(tmp);
		i++;
	}
	close(fd);
	split = ft_strsplit(file, '|');
	free(file);
	parse2(map, split, i);
}
