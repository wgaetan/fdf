/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 17:12:51 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:12:51 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int a;
	int i;

	a = 0;
	if (!(unsigned char)c)
	{
		i = ft_strlen(s);
		if (s[i] == (unsigned char)c)
			return ((char*)&s[i]);
	}
	while (s[a])
	{
		if (s[a] == (unsigned char)c)
			return ((char*)&s[a]);
		a++;
	}
	return (0);
}
