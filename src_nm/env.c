/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:18:52 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/21 11:06:32 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

t_symbols 	*ft_init_env()
{
	t_symbols	*env;

	env = malloc(sizeof(t_symbols));
	env-> type = ' ';
	env->hexvalue = NULL;
	env->name = NULL;
	env->next = NULL;
	return (env);
}

void		ft_print_symbols(t_symbols *env)
{
	t_symbols	*tmp;

	tmp = env;
	ft_printf("COUCOU 1");
	while (tmp && tmp->name != NULL)
	{
		ft_printf("COUCOU 2");
		ft_printf("%s %c %s\n", env->hexvalue, env->type, env->name);
		tmp = tmp->next;
	}
}

t_symbols	*ft_create_elem(char *name, char *value, char c)
{
	t_symbols	*new;

	new = malloc(sizeof(t_symbols));
	new->type = c;
	new->name = name;
	new->hexvalue = value;
	new->next = NULL;
	return (new);
}

void		ft_pushback(t_symbols *env, t_symbols *new)
{
	if (env->name == NULL)
	{
		env = new;
	}
}

