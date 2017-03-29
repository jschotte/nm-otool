/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 19:32:56 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/14 11:46:11 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_itoa_base_unsigned(unsigned long long value, int base)
{
	int					len;
	char				*ret;
	unsigned long long	tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = 1;
	tmp = value;
	while ((tmp = tmp / base))
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0 && value / base != 0)
	{
		ret[len] = value % base < 10 ? value % base + '0' : value % base + '7';
		value /= base;
		len--;
	}
	ret[len--] = value % base < 10 ? value % base + '0' : value % base + '7';
	return (ret);
}

char	*ft_itoa_base_long(long long value, int base)
{
	int			len;
	int			i;
	char		*ret;
	long long	tmp;

	if (base < 2 || base > 16)
		return (NULL);
	len = 1;
	tmp = value;
	while ((tmp = tmp / base))
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0 && value / base != 0)
	{
		i = ft_abs(value % base);
		ret[len] = i < 10 ? i + '0' : i + '7';
		value /= base;
		len--;
	}
	i = ft_abs(value % base);
	ret[len--] = i < 10 ? i + '0' : i + '7';
	return (ret);
}
