/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 21:06:47 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:00:02 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_right(unsigned char c, t_env *env)
{
	int	i;

	i = 1;
	if (env->zero == 0)
	{
		while (i < env->width)
		{
			ft_putchar(' ');
			env->ret++;
			i++;
		}
	}
	else
	{
		while (i < env->width)
		{
			ft_putchar('0');
			env->ret++;
			i++;
		}
	}
	if (!env->moins)
		ft_putchar(c);
	env->ret++;
}

static void	norme(t_env *env, unsigned char c)
{
	int i;

	i = 1;
	if (env->moins)
		ft_putchar(c);
	if (env->width != 0 && env->plus == 1)
	{
		ft_putchar(c);
		env->ret++;
		while (i < env->width)
		{
			ft_putchar(' ');
			env->ret++;
			i++;
		}
	}
}

void		conv_c(t_env *env, char *format)
{
	unsigned char	c;

	if (format[env->i] == 'C' || env->l == 1)
		conv_bigc(env);
	else
	{
		c = va_arg(env->ap, int);
		if (!env->width && !env->moins)
		{
			ft_putchar(c);
			env->ret++;
		}
		norme(env, c);
		if (env->width != 0 && env->plus == 0)
			ft_putstr_right(c, env);
	}
}

void		conv_bigc(t_env *env)
{
	unsigned int	c;
	char			*wc;
	char			**bin;

	c = va_arg(env->ap, unsigned int);
	wc = ft_itoa_base_unsigned(c, 2);
	bin = mask_unicode(wc);
	while (bin[env->size])
		env->size++;
	if (env->width > env->size && !env->moins)
	{
		env->width -= env->size;
		ft_putchar_nb(' ', env->width);
		env->size += env->width;
	}
	ft_putwchar(bin);
	if (env->width > env->size && env->moins)
	{
		env->width -= env->size;
		ft_putchar_nb(' ', env->width);
		env->size += env->width;
	}
	env->ret += env->size;
}
