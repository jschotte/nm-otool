/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:41:42 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:00:24 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_pourcent(t_env *env)
{
	int	i;

	i = 1;
	if (env->moins)
		ft_putchar('%');
	if (!env->zero || env->moins)
	{
		while (i < env->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	if (env->zero && !env->moins)
	{
		while (i < env->width)
		{
			ft_putchar('0');
			i++;
		}
	}
	if (!env->moins)
		ft_putchar('%');
	env->ret = env->ret + i;
}
