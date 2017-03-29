/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:30:42 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/04 14:06:30 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_firstspace(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] <= 32)
		i++;
	return (i);
}

static int		ft_lastspace(char *s)
{
	int i;

	i = ft_strlen(s);
	while (i != 0 && s[i] <= 32)
		i--;
	return (i);
}

static int		ft_countalpha(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]))
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		i;
	int		max;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = ft_firstspace((char*)s);
	max = ft_lastspace((char*)s);
	if (ft_countalpha((char*)s) == 0)
		return (ft_strnew(1));
	if (max == 0 || start == 0 || max < start)
	{
		str = ft_strnew(ft_strlen(s));
		return (ft_strcpy(str, s));
	}
	str = ft_strnew(max - start + 1);
	i = 0;
	while (i + start <= max)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
