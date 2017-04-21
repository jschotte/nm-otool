/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:00:19 by exam              #+#    #+#             */
/*   Updated: 2015/12/04 13:55:34 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_convert(int nb, char *str)
{
	int i;
	int j;

	j = 0;
	if (nb < 0)
	{
		str[j] = '-';
		j++;
		nb *= -1;
	}
	i = 1;
	while (nb / i > 9)
		i *= 10;
	while (i != 0)
	{
		str[j] = (nb / i) + 48;
		nb %= i;
		i /= 10;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			*ft_itoa(int nbr)
{
	int		i;
	int		j;
	char	*str;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		i = 0;
		j = nbr;
		while (j > 0)
		{
			i++;
			j = j / 10;
		}
		str = (char*)malloc(sizeof(str) * i + 1);
		str = ft_convert(nbr, str);
		return (str);
	}
}
