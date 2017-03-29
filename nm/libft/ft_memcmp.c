/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:01:29 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/03 10:44:01 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 != NULL && s2 != NULL)
	{
		str1 = (unsigned char*)s1;
		str2 = (unsigned char*)s2;
		i = 0;
		while (str1[i] == str2[i] && i < n)
			i++;
		if (i == n)
			return (0);
		else
			return (str1[i] - str2[i]);
	}
	else
		return (0);
}
