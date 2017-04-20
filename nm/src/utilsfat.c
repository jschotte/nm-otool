/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsfat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:16:23 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/20 13:26:28 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

char		*ft_getcputype(struct fat_arch *arch)
{
	cpu_type_t cpu;

	cpu = swapint32(arch->cputype);
	if (cpu == CPU_TYPE_I386)
		return (ft_strdup("i386"));
	else if (cpu == CPU_TYPE_X86_64)
		return (ft_strdup("x86_64"));
	else if (cpu == CPU_TYPE_ARM)
		return (ft_strdup("arm"));
	else if (cpu == CPU_TYPE_ARM64)
		return (ft_strdup("arm64"));
	else if (cpu == CPU_TYPE_POWERPC)
		return (ft_strdup("ppc"));
	else
		return (ft_strdup(""));
}

t_fat		*ft_init_fat(void)
{
	t_fat		*fat;

	fat = (t_fat*)malloc(sizeof(t_fat));
	fat->ptr = NULL;
	fat->cpuname = NULL;
	fat->next = NULL;
	return (fat);
}

t_fat		*ft_create_elem_fat(char *ptr, char *cpuname)
{
	t_fat		*new;

	new = (t_fat*)malloc(sizeof(t_fat));
	if (new == NULL)
		ft_exit("MALLOC error\n");
	new->ptr = ptr;
	new->cpuname = cpuname;
	new->next = NULL;
	return (new);
}

void		ft_pushback_fat(t_fat **env, t_fat *new)
{
	if (new && (new->ptr == NULL))
		ft_exit("MALLOC error\n");
	if (new != NULL)
	{
		if (!((*env)->ptr))
		{
			free(*env);
			*env = new;
		}
		else
		{
			new->next = *env;
			*env = new;
		}
	}
}

void		freefat(t_fat **fat)
{
	t_fat	*tmp;
	t_fat	*tmp2;

	tmp = *fat;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->cpuname);
		free(tmp);
		tmp = tmp2;
	}
}
