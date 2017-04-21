/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:29:50 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/01 18:15:37 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		str = ft_strnew(len);
		if (start > ft_strlen(s) || len > ft_strlen(s))
			return (NULL);
		while (i < len)
		{
			str[i] = s[i + start];
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
