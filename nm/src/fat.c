/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:16:23 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/20 13:26:28 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

int			ft_check_arch(t_fat **fat)
{
	t_fat	*tmp;

	tmp = *fat;
	while (tmp)
	{
		if (ft_strcmp(tmp->cpuname, "x86_64") == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			getsize(t_fat **fat, int arch)
{
	t_fat	*tmp;
	int		size;

	tmp = *fat;
	size = 0;
	while (tmp)
	{
		if (arch == 0 || ft_strcmp(tmp->cpuname, "x86_64") == 0)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

void		print_fat(t_fat **fat, t_symbols **env, char *str)
{
	t_fat		*tmp;
	int			hasarch;
	int			size;

	tmp = *fat;
	hasarch = ft_check_arch(fat);
	size = getsize(fat, hasarch);
	while (tmp != NULL)
	{
		if (hasarch == 0 || ft_strcmp(tmp->cpuname, "x86_64") == 0)
		{
			if (size > 1)
				ft_printf("%s (for architecture %s)\n", str, tmp->cpuname);
			ft_nm(tmp->ptr, str, *env);
			*env = NULL;
		}
		tmp = tmp->next;
	}
	freefat(fat);
}

void		ft_fat(char *ptr, t_symbols **env, int reverse, char *str)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					i;
	int					test;
	t_fat				*fat;

	i = 0;
	fat = ft_init_fat();
	header = (struct fat_header *)ptr;
	arch = (void*)ptr + sizeof(*header);
	while (i < swapint32(header->nfat_arch))
	{
		ft_pushback_fat(&fat, ft_create_elem_fat((void*)ptr
					+ swapint32(arch->offset), ft_getcputype(arch)));
		arch = (void*)arch + sizeof(struct fat_arch);
		i++;
	}
	print_fat(&fat, env, str);
}
