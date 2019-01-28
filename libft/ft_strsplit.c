/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 11:14:52 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 11:14:54 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		countlen(char *str, char c)
{
	int a;

	a = 0;
	while (*str && *str != c)
	{
		a++;
		str++;
	}
	return (a);
}

static int		counttab(char *str, char c)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] != c && (str[a + 1] == c || str[a + 1] == '\0'))
			count++;
		a++;
	}
	return (count);
}

static int		ft_return(char *str, char c)
{
	if (str)
	{
		while (*str == c)
		{
			if (*str == '\0')
				return (0);
			str++;
		}
	}
	return (1);
}

char			**ft_strsplit(char *str, char c)
{
	char	**tab;
	int		a;
	int		b;

	a = 0;
	b = 0;
	tab = NULL;
	if (!(str && c))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (counttab(str, c) + 1))))
		return (NULL);
	while (b < counttab(str, c))
	{
		while (str[a] && str[a] == c)
			a++;
		if (!(tab[b] = (char*)malloc(sizeof(char) * (countlen(&str[a], c)))))
			return (NULL);
		tab[b] = ft_memcpy((char*)tab[b], (char*)&str[a], countlen(&str[a], c));
		tab[b][countlen(&str[a], c)] = '\0';
		while (str[a] && str[a] != c)
			a++;
		b++;
	}
	tab[b] = NULL;
	return (ft_return(str, c) == 1 ? tab : NULL);
}
