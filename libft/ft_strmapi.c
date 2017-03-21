/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:26:29 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/01 17:51:04 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		while (i < ft_strlen(s))
		{
			str[i] = f(i, s[i]);
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
