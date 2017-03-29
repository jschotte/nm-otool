/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/29 20:41:38 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

char	*ft_strcpyend(char *dest, char *src)
{
	int	len_d;
	int	len_s;

	len_d = ft_strlen(dest) - 1;
	len_s = ft_strlen(src) - 1;
	while (len_s >= 0)
	{
		dest[len_d] = src[len_s];
		len_d--;
		len_s--;
	}
	return (dest);
}

char	*ft_get_value(long long value, int len)
{
	char	*hex;
	char	*tmp;

	if (value != 0)
	{
		if (len == 8)
			hex = ft_strdup("00000000");
		else
			hex = ft_strdup("0000000000000000");
		tmp = ft_itoa_base_str(value, 16);
		if (hex == NULL || tmp == NULL)
			ft_exit("MALLOC error\n");
		ft_strcpyend(hex, tmp);
		free(tmp);
		return (hex);
	}
	else
	{
		if (len == 8)
			return (ft_strdup("        "));
		else
			return (ft_strdup("                "));
	}
}
