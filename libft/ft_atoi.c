/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 17:12:21 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 10:57:59 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	a;
	int	pos;
	int	nb;

	a = 0;
	pos = 1;
	nb = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
		if (str[a++] == '-')
			pos = -1;
	while (str[a] && (str[a] >= '0' && str[a] <= '9'))
		nb = (nb * 10) + (str[a++] - '0');
	return ((int)nb * (int)pos);
}
