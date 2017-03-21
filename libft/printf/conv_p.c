/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 19:10:06 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:00:18 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero(t_env *env, char *s)
{
	while (env->size < env->width)
	{
		s = ft_strjoin(s, ft_strdup("0"));
		env->size++;
	}
	env->size = ft_strlen(s);
	s = ft_putstrl(s);
	if (!env->punct)
		ft_putstr(s);
	free(s);
}

static void	norme(t_env *env, char *s)
{
	while (env->size < env->width)
	{
		if (env->moins)
			s = ft_strjoin(s, ft_strdup(" "));
		else
			s = ft_strjoin(ft_strdup(" "), s);
		env->size++;
	}
	env->size = ft_strlen(s);
	s = ft_putstrl(s);
	if (!env->punct)
		ft_putstr(s);
	free(s);
}

void		conv_p(t_env *env)
{
	char	*s;

	s = ft_itoa_base_unsigned(va_arg(env->ap, unsigned long long), 16);
	env->size = ft_strlen(s);
	while (env->size < env->precision)
	{
		s = ft_freejoin(ft_strdup("0"), s);
		env->size++;
	}
	if (!env->punct)
		s = ft_freejoin(ft_strdup("0x"), s);
	else
	{
		ft_putstr("0x");
		env->ret++;
	}
	env->size += 2;
	if (env->zero && !env->moins)
		zero(env, s);
	else
		norme(env, s);
	env->ret += env->size;
}
