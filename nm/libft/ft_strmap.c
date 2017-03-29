/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:26:29 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/01 18:13:27 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		while (i < ft_strlen(s))
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	else
		return (NULL);
}
