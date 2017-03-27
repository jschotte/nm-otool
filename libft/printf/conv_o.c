/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 21:54:04 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/27 14:50:45 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flags(unsigned long long o, t_env *env)
{
	char	*s;

	if (env->punct == 1 && o == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(o, 8);
	env->size = ft_strlen(s);
	while (env->size < env->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		env->size++;
	}
	if (env->diese && s[0] != 0)
		env->size++;
	if (env->diese && s[0] != '0')
		s = ft_freejoin(ft_strdup("0"), s);
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

static char	*zero(unsigned long long o, t_env *env)
{
	char	*s;

	if (env->punct == 1 && o == 0)
		s = ft_strnew(0);
	else
		s = ft_itoa_base_unsigned(o, 8);
	env->size = ft_strlen(s);
	if (env->precision)
		while (env->size++ < env->precision)
			s = ft_freejoin(ft_strdup("0"), s);
	else
		while (env->size++ < env->width)
			s = ft_freejoin(ft_strdup("0"), s);
	if (env->diese && s[0] != '0')
		env->size++;
	if (env->diese && s[0] != '0')
		s = ft_freejoin(ft_strdup("0"), s);
	while (env->size++ <= env->width)
	{
		if (env->moins)
			s = ft_freejoin(s, ft_strdup(" "));
		else
			ft_freejoin(ft_strdup(" "), s);
	}
	return (s);
}

void		conv_o(t_env *env, char *format)
{
	unsigned long long	o;
	char				*s;

	o = va_arg(env->ap, unsigned long long);
	if (env->l || format[env->i] == 'O')
		o = (unsigned long)o;
	else if (env->h)
		o = (unsigned short int)o;
	else if (env->hh)
		o = (unsigned char)o;
	else if (env->j)
		o = (uintmax_t)o;
	else if (env->z)
		o = (size_t)o;
	else if (!env->ll)
		o = (unsigned int)o;
	if (env->zero && !env->moins)
		s = zero(o, env);
	else
		s = flags(o, env);
	env->size = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
	env->ret += env->size;
}
