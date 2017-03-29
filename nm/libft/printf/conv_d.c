/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:47:56 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:00:08 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags_norme(long long d, t_env *env, char *s)
{
	if (env->plus && d >= 0)
		s = ft_freejoin(ft_strdup("+"), s);
	if (env->space && d >= 0 && !env->plus)
		s = ft_freejoin(ft_strdup(" "), s);
	if (d < 0)
		s = ft_freejoin(ft_strdup("-"), s);
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

static char	*flags(long long d, t_env *env)
{
	char	*s;
	int		i;

	if (env->punct == 1 && d == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_long(d, 10);
	i = ft_strlen(s);
	if (d < 0 || env->plus || env->space)
		env->size = i + 1;
	else
		env->size = i;
	while (i < env->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		env->size++;
		i++;
	}
	s = flags_norme(d, env, s);
	return (s);
}

static char	*zero_norme(t_env *env, long long d, char *s)
{
	if (env->plus && d >= 0)
		s = ft_freejoin(ft_strdup("+"), s);
	if (env->space && d >= 0 && !env->plus)
		s = ft_freejoin(ft_strdup(" "), s);
	if (d < 0)
		s = ft_freejoin(ft_strdup("-"), s);
	while (env->size < env->width)
	{
		if (env->precision && !env->punct)
			s = ft_freejoin(ft_strdup(" "), s);
		else
			s = ft_freejoin(ft_strdup("0"), s);
		env->size++;
	}
	return (s);
}

static char	*zero(long long d, t_env *env)
{
	char	*s;
	int		i;

	if (env->punct == 1 && d == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_long(d, 10);
	i = ft_strlen(s);
	if (d < 0 || env->plus || env->space)
		env->size = i + 1;
	else
		env->size = i;
	if (env->precision)
		while (i < env->precision && env->size < env->width)
		{
			s = ft_freejoin(ft_strdup("0"), s);
			i++;
			env->size++;
		}
	else
		while (env->size++ < env->width)
			s = ft_freejoin(ft_strdup("0"), s);
	s = zero_norme(env, d, s);
	return (s);
}

void		conv_d(char *format, t_env *env)
{
	long long	d;
	char		*s;

	d = va_arg(env->ap, long long);
	if (env->l || format[env->i] == 'D')
		d = (long)d;
	else if (env->h)
		d = (short int)d;
	else if (env->hh)
		d = (signed char)d;
	else if (env->j)
		d = (intmax_t)d;
	else if (env->z)
		d = (ssize_t)d;
	else if (!env->ll)
		d = (int)d;
	if (env->zero && !env->moins)
		s = zero(d, env);
	else
		s = flags(d, env);
	env->size = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	env->ret += env->size;
}
