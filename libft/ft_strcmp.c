/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 17:12:51 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:12:51 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int a;

	a = 0;
	while (s1[a] && ((const char)s1[a] == (const char)s2[a]))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
