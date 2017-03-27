/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/27 16:47:45 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void	ft_print(int nsyms, int symoff, int stroff, char *ptr, t_symbols **env)
{
	int				i;
	char			*stringtable;
	struct nlist_64 *array;
	t_symbols	*new;

	array = (void *) ptr + symoff;
	stringtable = (void *) ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		//ft_printf("%s", stringtable + array[i].n_un.n_strx);
		new = ft_create_elem(ft_strdup(stringtable + array[i].n_un.n_strx),
				ft_get_value(array[i].n_value, 16), ft_get_type(array[i].n_type - 1,
					array[i].n_sect));
		//printf("%hhu\n", array[i].n_type);
		ft_pushback(env, new);
		i++;
	}
}

void	ft_nm_64(char *ptr, t_symbols **env)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command	*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *) ptr;
	ncmds = header->ncmds;
	lc = (void *) ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			ft_print(sym->nsyms, sym->symoff, sym->stroff, ptr, env);
			break ;
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
}
