/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 17:12:51 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:12:51 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;

	a = 0;
	str = NULL;
	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (s[start] && len--)
		{
			str[a++] = s[start++];
		}
	}
	return (str);
}
