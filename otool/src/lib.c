/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 16:11:23 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 16:24:16 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void	ft_lib(char *ptr, char *str)
{
	unsigned int	size;

	size = ft_atoi((char*)(ptr + 0x38));
	ptr = (char*)((void*)ptr + size + 0x3C);
	while (ptr != NULL)
	{
		size = ft_atoi((char*)(ptr + 0x38));
		if (ft_strcmp("", (char*)(ptr + 0x44)) == 0)
			break ;
		ft_printf("\n%s(%s):\n", str, (char*)(ptr + 0x44));
		if (ft_strlen((char*)(ptr + 0x44)) >= 19)
			ft_nm(ptr + 0x60, str);
		else if (ft_strlen((char*)(ptr + 0x44)) > 8)
			ft_nm(ptr + 0x58, str);
		else
			ft_nm(ptr + 0x50, str);
		ptr = (char*)((void*)ptr + size + 0x3C);
		if (size == 0)
			break ;
	}
}
