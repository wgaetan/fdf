/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 17:12:51 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:12:51 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*tab;
	int		a;

	a = 0;
	tab = NULL;
	while (str[a])
		a++;
	if (!(tab = (char*)malloc(sizeof(char) * (a) + 1)))
		return (NULL);
	if (tab == NULL)
		return (NULL);
	a = 0;
	while (str[a])
	{
		tab[a] = str[a];
		a++;
	}
	tab[a] = '\0';
	return (tab);
}
