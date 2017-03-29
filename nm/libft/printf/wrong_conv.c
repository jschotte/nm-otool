/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 06:33:55 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 10:59:08 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wrong_conv(char *format, t_env *env)
{
	if (env->width)
		env->ret += env->width;
	else
		env->ret++;
	if (!env->moins)
	{
		if (env->zero)
			ft_putchar_nb('0', env->width - 1);
		else
			ft_putchar_nb(' ', env->width - 1);
	}
	ft_putchar(format[env->i]);
	if (env->moins)
	{
		if (env->zero)
			ft_putchar_nb('0', env->width - 1);
		else
			ft_putchar_nb(' ', env->width - 1);
	}
}
