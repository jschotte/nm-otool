/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:34:16 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/21 14:45:35 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_convert(char *str, long long nb, int b)
{
	long long i;
	int j;
	static char letter[16] = {"0123456789abcdef"};
	
	j = 0;
	if (nb < 0 && b == 10)
	{
		str[j] = '-';
		j++;
		nb *= -1;
	}
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

char	*ft_itoa_base_str(long long value, int base)
{
	int i;
	long long j;
	char *str;

	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	j = value;
	i = 0;
	while (j > 0)
	{
		j /= base;
		i++;
	}
	str = (char*)malloc(sizeof(str) * (i + 1));
	str = ft_convert(str, value, base);
	return (str);
}
