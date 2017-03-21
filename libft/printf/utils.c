/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 22:30:44 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:01:30 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_zero(int k, t_env *env)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putchar('0');
		env->ret++;
		i++;
	}
}

void	ft_put_space(int k, t_env *env)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_putchar(' ');
		env->ret++;
		i++;
	}
}

void	ft_putchar_nb(char c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putchar(c);
		j++;
	}
}

char	*ft_putstrl(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}

int		ft_putnstr(char *s, t_env *env, int i)
{
	int a;

	a = 0;
	if (env->precision < i)
	{
		while (a < env->precision)
		{
			ft_putchar(s[a]);
			a++;
		}
	}
	else if (env->precision > i)
	{
		ft_putstr(s);
		a = i++;
		ft_putchar(s[a]);
	}
	return (a);
}
