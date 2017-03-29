/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 21:27:03 by jschotte          #+#    #+#             */
/*   Updated: 2017/02/13 18:48:43 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags(unsigned long long x, t_env *env)
{
	char	*s;

	if (env->punct && x == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(x, 16);
	env->size = ft_strlen(s);
	while (env->size < env->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		env->size++;
	}
	if (env->diese && x)
		s = ft_freejoin(ft_strdup("0X"), s);
	if (env->diese)
		env->size += 2;
	while (env->size < env->width)
	{
		if (env->moins)
			s = ft_freejoin(s, ft_strdup(" "));
		else
			s = ft_freejoin(ft_strdup(" "), s);
		env->size++;
	}
	return (s);
}

static char	*zero_norme(unsigned long long x, t_env *env, char *s)
{
	if (env->precision)
	{
		while (env->size++ < env->precision)
			s = ft_freejoin(ft_strdup("0"), s);
		if (env->diese)
			env->size += 2;
	}
	else
	{
		if (env->diese)
			env->size += 2;
		while (env->size++ < env->width)
			s = ft_freejoin(ft_strdup("0"), s);
	}
	if (env->diese && x)
		s = ft_freejoin(ft_strdup("0X"), s);
	while (env->size <= env->width)
	{
		if (env->moins)
			s = ft_freejoin(s, ft_strdup(" "));
		else
			s = ft_freejoin(ft_strdup(" "), s);
		env->size++;
	}
	return (s);
}

static char	*zero(unsigned long long x, t_env *env)
{
	char	*s;

	if (env->punct && x == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(x, 16);
	env->size = ft_strlen(s);
	s = zero_norme(x, env, s);
	return (s);
}

void		conv_x(t_env *env, char *format)
{
	unsigned long long	x;
	char				*s;

	x = va_arg(env->ap, unsigned long long);
	if (env->l)
		x = (unsigned long)x;
	else if (env->h)
		x = (unsigned short int)x;
	else if (env->hh)
		x = (unsigned char)x;
	else if (env->j)
		x = (uintmax_t)x;
	else if (env->z)
		x = (size_t)x;
	else if (!env->ll)
		x = (unsigned int)x;
	if (env->zero && !env->moins)
		s = zero(x, env);
	else
		s = flags(x, env);
	env->ret += ft_strlen(s);
	if (format[env->i] == 'x')
		s = ft_putstrl(s);
	ft_putstr(s);
	ft_strdel(&s);
}
