/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 05:20:33 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:01:03 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_width_norme(char *format, t_env *env, int i)
{
	char	*str;

	if (ft_isdigit(format[i]) && format[i] != '0')
	{
		while (ft_isdigit(format[i]))
			i++;
		i -= env->i;
		str = ft_strnew(i);
		i = 0;
		while (ft_isdigit(format[env->i]))
		{
			str[i] = format[env->i];
			env->i++;
			i++;
		}
		env->width = ft_atoi(str);
		ft_strdel(&str);
	}
}

void		flag_width(char *format, t_env *env)
{
	int	i;

	i = env->i;
	if ((ft_isdigit(format[i]) && format[i] != '0') || format[i] == '*')
	{
		if (format[i] == '*')
		{
			env->width = va_arg(env->ap, int);
			env->i++;
			i++;
		}
		flag_width_norme(format, env, i);
		if (format[env->i] == '*')
		{
			env->width = va_arg(env->ap, int);
			env->i++;
		}
		if (env->width < 0)
		{
			env->moins = 1;
			env->width *= -1;
		}
	}
	else if (format[i] == '0')
		env->fail = 1;
}

static void	flag_precision_norme(char *format, t_env *env, int i)
{
	char	*str;

	if (format[env->i + 1] == '0')
		env->punct = 1;
	while (ft_isdigit(format[i]))
		i++;
	env->i++;
	i = i - env->i;
	str = ft_strnew(i);
	i = 0;
	while (ft_isdigit(format[env->i]))
	{
		str[i] = format[env->i];
		env->i++;
		i++;
	}
	env->precision = ft_atoi(str);
	free(str);
}

void		flag_precision(char *format, t_env *env)
{
	int	i;

	i = env->i + 1;
	if ((format[env->i] == '.' && ft_isdigit(format[env->i + 1])) \
		|| (format[env->i] == '.' && format[env->i + 1] == '*'))
	{
		if (format[env->i] == '.' && ft_isdigit(format[env->i + 1]))
			flag_precision_norme(format, env, i);
		if (format[env->i + 1] == '*')
		{
			env->precision = va_arg(env->ap, int);
			env->i += 2;
			if (env->precision <= 0)
				env->punct = 1;
		}
	}
	else if (format[env->i] == '.' && !ft_isdigit(format[env->i + 1]))
	{
		env->i++;
		env->punct = 1;
	}
}

void		flag_length(char *format, t_env *env)
{
	if (format[env->i] == 'h' && format[env->i + 1] == 'h')
	{
		env->hh = 1;
		env->i++;
	}
	else if (format[env->i] == 'h' && format[env->i + 1] != 'h')
		env->h = 1;
	else if (format[env->i] == 'l' && format[env->i + 1] != 'l')
		env->l = 1;
	else if (format[env->i] == 'l' && format[env->i + 1] == 'l')
	{
		env->ll = 1;
		env->i++;
	}
	else if (format[env->i] == 'z')
		env->z = 1;
	else if (format[env->i] == 'j')
		env->j = 1;
	if ((env->hh == 1 || env->h == 1 || env->ll == 1 || env->l == 1	\
		|| env->j == 1 || env->z == 1) && format[env->i + 1] != '\0')
		env->i++;
	else if ((env->hh == 1 || env->h == 1 || env->ll == 1 || env->l == 1 \
			|| env->j == 1 || env->z == 1) && format[env->i + 1] == '\0')
		env->fail++;
}
