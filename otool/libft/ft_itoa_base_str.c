/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:34:16 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 13:24:18 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_convert(char *str, unsigned int nb, unsigned int b)
{
	unsigned int	i;
	int				j;
	static char		letter[16] = {"0123456789abcdef"};

	j = 0;
	i = 1;
	while (nb / i > b - 1)
		i *= b;
	while (i != 0)
	{
		str[j] = letter[nb / i];
		nb %= i;
		i /= b;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_itoa_base_str(unsigned int value, int base)
{
	int				i;
	unsigned int	j;
	char			*str;

	j = value;
	i = 0;
	while (j > 0)
	{
		j /= base;
		i++;
	}
	str = (char*)malloc(sizeof(str) * (i + 1));
	if (str == NULL)
		return (NULL);
	str = ft_convert(str, value, base);
	return (str);
}
