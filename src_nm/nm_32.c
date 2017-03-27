/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/27 17:58:38 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void	ft_print_32(int nsyms, int symoff, int stroff, char *ptr, t_symbols **env)
{
	int				i;
	char			*stringtable;
	struct nlist *array;
	t_symbols	*new;

	array = (void *) ptr + symoff;
	stringtable = (void *) ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		//ft_printf("%s", stringtable + array[i].n_un.n_strx);
		new = ft_create_elem(ft_strdup(stringtable + array[i].n_un.n_strx),
				ft_get_value(array[i].n_value, 8), ft_get_type(array[i].n_type - 1,
					array[i].n_sect));
		ft_pushback(env, new);
		i++;
	}
}

void	ft_nm_32(char *ptr, t_symbols **env)
{
	int						ncmds;
	int						i;
	struct mach_header	*header;
	struct load_command	*lc;
	struct symtab_command	*sym;

	header = (struct mach_header *) ptr;
	ncmds = header->ncmds;
	lc = (void *) ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			ft_print_32(sym->nsyms, sym->symoff, sym->stroff, ptr, env);
			break ;
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
}
