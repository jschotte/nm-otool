/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:18:52 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/27 13:51:27 by jschotte         ###   ########.fr       */
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
	while (tmp && tmp->name != NULL)
	{
		if (ft_strcmp(tmp->name, "radr://5614542") != 0 && tmp->type != ' ')
		{
			if (ft_strchr(tmp->hexvalue, ' ') != NULL
						&& tmp->type == 'T')
				ft_printf("%017 %c %s\n",  tmp->type, tmp->name);
			else
				ft_printf("%s %c %s\n", tmp->hexvalue, tmp->type, tmp->name);
		}
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

void	ft_swaplist(t_symbols *l1, t_symbols *l2)
{
	char	*name;
	char	*value;
	char	c;

	name = l1->name;
	value = l1->hexvalue;
	c = l1->type;
	l1->name = l2->name;
	l1->hexvalue = l2->hexvalue;
	l1->type = l2->type;
	l2->name = name;
	l2->hexvalue = value;
	l2->type = c;
}

t_symbols	*ft_sort_list(t_symbols *lst)
{
	t_symbols *temp;

	temp = lst;
	while (lst != NULL && lst->next != NULL)
	{
		if (ft_strcmp(lst->name, lst->next->name) > 0)
		{
			ft_swaplist(lst, lst->next);
			lst = temp;
		}
		else
			lst = lst->next;
	}
	return (temp);
}

void		ft_pushback(t_symbols **env, t_symbols *new)
{
	if (!((*env)->name))
		*env = new;
	else
	{
		new->next = *env;
		*env = new;
	}
}

