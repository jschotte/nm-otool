/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:00:06 by jschotte          #+#    #+#             */
/*   Updated: 2015/11/30 15:13:29 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (char)c)
			return (&s1[i + 1]);
		i++;
	}
	return (NULL);
}
