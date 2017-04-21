/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:55:10 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 16:27:12 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		*ft_exit(char *error)
{
	ft_putstr_fd(error, 3);
	return (NULL);
}

uint32_t	swapint32(uint32_t x)
{
	return ((((uint32_t)(x) & 0xff000000) >> 24) |
			(((uint32_t)(x) & 0x00ff0000) >> 8) |
			(((uint32_t)(x) & 0x0000ff00) << 8) |
			(((uint32_t)(x) & 0x000000ff) << 24));
}