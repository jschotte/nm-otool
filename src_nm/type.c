/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/27 11:31:18 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

char	ft_get_type(int value, int sect)
{
	//printf(" %d %d\n", value, sect);
	if (value == N_SECT)
	{
		if (sect == 1)
			return ('T');
		else
			return ('S');
	}
	else if (value == N_SECT - 1)
	{
		if (sect == 1)
			return ('t');
		else
			return ('d');
	}
	else if (value == N_UNDF)
		return ('U');
	else if (value == N_ABS)
		return ('A');
	else if (value == N_PBUD)
		return ('P');
	else if (value == N_INDR)
		return ('I');
	else if (sect == N_STAB)
		return ('X');
	else
		return (' ');
}
