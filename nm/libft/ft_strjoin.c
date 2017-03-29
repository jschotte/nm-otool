/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:30:22 by jschotte          #+#    #+#             */
/*   Updated: 2015/12/01 18:20:00 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		j = i;
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = '\0';
	}
	else
		str = NULL;
	return (str);
}
