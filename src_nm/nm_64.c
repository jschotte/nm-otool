/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/23 14:17:11 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

char	ft_get_type(int value, int sect)
{
	//printf(" %d %d\n", value, sect);
	if (value == N_SECT)
	{
		if (sect == 1)
			return ('T');
		else
			return ('S');
	}
	else if (value == N_SECT - 1)
	{
		if (sect == 1)
			return ('t');
		else
			return ('d');
	}
	else if (value == N_UNDF)
		return ('U');
	else if (value == N_ABS)
		return ('A');
	else if (value == N_PBUD)
		return ('P');
	else if (value == N_INDR)
		return ('I');
	else if (sect == N_STAB)
		return ('X');
	else
		return (' ');
}

char	*ft_get_value(long long value)
{
	char	*hex;

	if (value != 0)
	{
		hex = ft_itoa_base_str(value, 16);
		return (hex);
	}
	else
		return (ft_strdup(""));
}

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
		//printf("%s", stringtable + array[i].n_un.n_strx);
		new = ft_create_elem(ft_strdup(stringtable + array[i].n_un.n_strx),
				ft_get_value(array[i].n_value), ft_get_type(array[i].n_type - 1,
					array[i].n_sect));
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
