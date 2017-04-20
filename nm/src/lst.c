/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:18:52 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/20 13:22:01 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

t_symbols		*ft_init_env(t_symbols *old)
{
	t_symbols	*env;

	if (old != NULL)
		return (old);
	env = (t_symbols*)malloc(sizeof(t_symbols));
	env->type = ' ';
	env->hexvalue = NULL;
	env->name = NULL;
	env->next = NULL;
	return (env);
}

void			*ft_exit(char *error)
{
	ft_putstr_fd(error, 3);
	return (NULL);
}

void			ft_print_symbols(t_symbols **env)
{
	t_symbols	*tmp;
	t_symbols	*tmp2;

	*env = ft_sort_list(*env);
	tmp = *env;
	while (tmp && tmp->name != NULL)
	{
		tmp2 = tmp->next;
		if (ft_strcmp(tmp->name, "radr://5614542") != 0
				&& ft_strcmp(tmp->name, "") != 0
				&& tmp->type != 'u'
				&& tmp->type != ' ')
		{
			if (ft_strchr(tmp->hexvalue, ' ') != NULL
					&& tmp->type == 'T')
				ft_printf("%017 %c %s\n", tmp->type, tmp->name);
			else
				ft_printf("%s %c %s\n", tmp->hexvalue, tmp->type, tmp->name);
		}
		free(tmp->name);
		free(tmp->hexvalue);
		free(tmp);
		tmp = tmp2;
	}
}
