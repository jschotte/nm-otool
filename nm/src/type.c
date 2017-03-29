/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/29 19:44:33 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

char	ft_get_type_nsect(int sect, t_count *seg)
{
	if (sect == seg->text)
		return ('t');
	else if (sect == seg->data)
		return ('d');
	else if (sect == seg->bss)
		return ('b');
	else
		return ('s');
}

char	ft_get_type_v2(unsigned char type, unsigned char sect,
		unsigned long value, t_count *seg)
{
	char c;

	c = ' ';
	if ((type & N_TYPE) == N_UNDF)
	{
		c = 'u';
		if (value != 0)
			c = 'c';
	}
	else if ((type & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((type & N_TYPE) == N_ABS)
		c = 'a';
	else if ((type & N_TYPE) == N_INDR)
		c = 'i';
	else if ((type & N_TYPE) == N_SECT)
		c = ft_get_type_nsect(sect, seg);
	if ((type & N_EXT) && c != ' ')
		c -= 32;
	return (c);
}
