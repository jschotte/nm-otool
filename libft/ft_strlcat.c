/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:27:52 by jschotte          #+#    #+#             */
/*   Updated: 2015/11/30 14:02:34 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	j = 0;
	while (dst[j] != '\0' && j < size)
		j++;
	i = j;
	k = 0;
	while (src[k] != '\0' && j < size - 1)
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	if (i < size)
		dst[j] = '\0';
	return (ft_strlen(src) + i);
}
