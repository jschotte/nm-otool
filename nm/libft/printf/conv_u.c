/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:29:10 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:00:39 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags_again_norme(t_env *env, int i)
{
	if (env->precision > i)
		env->width = env->width - env->precision + i;
	if (env->precision > i)
		env->precision = env->precision + env->width - i;
	while (i < env->width)
	{
		if (env->moins == 0 && env->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	while (i < env->precision)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

static int	flags_again(t_env *env, int i)
{
	if (env->width > env->precision && env->precision)
		i = flags_again_norme(env, i);
	else if (env->width > env->precision && !env->precision)
	{
		while (i < env->width)
		{
			if (env->moins == 0 && env->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i++;
		}
	}
	else if (env->width < env->precision)
	{
		while (i < env->precision)
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static void	flags(t_env *env, int i, unsigned long long u)
{
	if (env->moins == 1 && env->punct == 0)
		ft_putnbr_u(u);
	i = flags_again(env, i);
	if (env->moins == 0 && env->punct == 0)
		ft_putnbr_u(u);
	env->ret = env->ret + i;
}

void		ft_putnbr_u(unsigned long long value)
{
	if (value >= 10)
		ft_putnbr_u(value / 10);
	ft_putchar(value % 10 + '0');
}

void		conv_u(t_env *env, char *format)
{
	unsigned long long	u;
	unsigned long long	tmp;
	int					i;

	u = va_arg(env->ap, unsigned long long);
	if (env->l || format[env->i] == 'U')
		u = (unsigned long)u;
	else if (env->h)
		u = (unsigned short int)u;
	else if (env->hh)
		u = (unsigned char)u;
	else if (env->j)
		u = (uintmax_t)u;
	else if (env->z)
		u = (size_t)u;
	else if (!env->ll)
		u = (unsigned int)u;
	tmp = u;
	i = 1;
	while ((tmp = tmp / 10))
		i++;
	if (env->punct == 1 && u == 0)
		i--;
	flags(env, i, u);
}
