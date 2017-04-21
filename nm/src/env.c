/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:18:52 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 18:20:56 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

t_symbols		*ft_create_elem(char *name, char *value, char c)
{
	t_symbols	*new;

	if (c != ' ')
	{
		new = (t_symbols*)malloc(sizeof(t_symbols));
		if (new == NULL)
			ft_exit("MALLOC error\n");
		new->type = c;
		new->name = name;
		new->hexvalue = value;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

void			ft_swaplist(t_symbols *l1, t_symbols *l2)
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

t_symbols		*ft_sort_list(t_symbols *lst)
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
		else if (ft_strcmp(lst->name, lst->next->name) == 0
			&& ft_strcmp(lst->hexvalue, lst->next->hexvalue) > 0)
		{
			ft_swaplist(lst, lst->next);
			lst = temp;
		}
		else
			lst = lst->next;
	}
	return (temp);
}

int				ft_already_in(t_symbols **env, char *str, char *hex)
{
	t_symbols *tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0
				&& ft_strcmp(tmp->hexvalue, hex) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			ft_pushback(t_symbols **env, t_symbols *new)
{
	if (new && (new->hexvalue == NULL || new->name == NULL))
		ft_exit("MALLOC error\n");
	if (new != NULL)
	{
		if (!((*env)->name))
		{
			free(*env);
			*env = new;
		}
		else
		{
			if (ft_already_in(env, new->name, new->hexvalue) == 0)
			{
				new->next = *env;
				*env = new;
			}
		}
	}
}
