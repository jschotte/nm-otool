/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:29:59 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/13 18:27:39 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init(t_env *env)
{
	env->diese = 0;
	env->moins = 0;
	env->plus = 0;
	env->space = 0;
	env->zero = 0;
	env->width = 0;
	env->precision = 0;
	env->hh = 0;
	env->h = 0;
	env->ll = 0;
	env->l = 0;
	env->j = 0;
	env->z = 0;
	env->punct = 0;
	env->size = 0;
}

static void	ft_check_option(char *format, t_env *env)
{
	ft_init(env);
	env->i++;
	while (format[env->i] == '#' || format[env->i] == '-' || format[env->i] \
			== '+' || format[env->i] == ' ' || format[env->i] == '0')
	{
		flag_diese(format, env);
		flag_moins(format, env);
		flag_plus(format, env);
		flag_space(format, env);
		flag_zero(format, env);
		env->i++;
	}
	flag_width(format, env);
	flag_precision(format, env);
	flag_length(format, env);
	ft_conv(format, env);
}

static int	ft_start(char *format, t_env *env)
{
	env->i = 0;
	while (format[env->i] && format)
	{
		env->fail = 0;
		if (format[env->i] == '%' && format[env->i + 1] == '\0')
			break ;
		else if (format[env->i] == '%')
			ft_check_option(format, env);
		else if (env->fail == 0 && format[env->i] != '\0')
		{
			ft_putchar(format[env->i]);
			env->ret++;
		}
		if (format[env->i])
			env->i++;
	}
	return (env->ret);
}

int			ft_printf(char *format, ...)
{
	t_env	env;
	int		ret;

	env.ret = 0;
	va_start(env.ap, format);
	ret = ft_start(format, &env);
	va_end(env.ap);
	return (env.ret);
}
