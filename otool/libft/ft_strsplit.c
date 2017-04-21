/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:31:21 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/03 10:37:05 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_countword(char *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		else
		{
			while (s[i] && s[i] != c)
				i++;
			nb++;
		}
	}
	return (nb);
}

static int		ft_lenw(char *s, char c, int j)
{
	int i;

	i = j;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	char	**ft_return(char **tab, int nb)
{
	tab[nb] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nbw;
	int		j;

	if (s != NULL)
	{
		nbw = ft_countword((char*)s, c);
		tab = ft_memalloc(nbw + 1);
		if (tab == NULL)
			return (NULL);
		j = 0;
		i = 0;
		while (i < nbw)
		{
			while (s[j] == c)
				j++;
			tab[i] = (char*)malloc(sizeof(s) * (ft_lenw((char*)s, c, j) + 1));
			tab[i] = ft_strsub((char*)s, j, ft_lenw((char*)s, c, j) - j);
			j = ft_lenw((char*)s, c, j) + 1;
			i++;
		}
		return (ft_return(tab, nbw));
	}
	return (NULL);
}
