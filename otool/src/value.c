/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 10:20:21 by jschotte         ###   ########.fr       */
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

char	*ft_get_value_next(int len)
{
	char	*hex;

	if (len == 8)
		hex = ft_strdup("        ");
	else
		hex = ft_strdup("                ");
	if (hex == NULL)
		return (ft_exit("MALLOC error\n"));
	else
		return (hex);
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
			return (ft_exit("MALLOC error\n"));
		ft_strcpyend(hex, tmp);
		free(tmp);
		return (hex);
	}
	else
		return (ft_get_value_next(len));
}
