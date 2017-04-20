/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/20 12:47:56 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_print_32(struct symtab_command *sym, char *ptr, t_symbols **env,
		t_count *seg)
{
	int				i;
	char			*stringtable;
	struct nlist	*array;
	t_symbols		*new;

	array = (void *)ptr + sym->symoff;
	stringtable = (void *)ptr + sym->stroff;
	i = 0;
	while (i < sym->nsyms)
	{
		new = ft_create_elem(ft_strdup(stringtable + array[i].n_un.n_strx),
				ft_get_value(array[i].n_value, 8),
				ft_get_type_v2(array[i].n_type, array[i].n_sect,
					array[i].n_value, seg));
		ft_pushback(env, new);
		i++;
	}
}

t_count		*ft_init_count_32(t_count *old)
{
	t_count *env_seg;

	env_seg = old;
	if (env_seg == NULL)
	{
		env_seg = malloc(sizeof(t_count));
		if (env_seg == NULL)
			ft_exit("MALLOC error\n");
		env_seg->text = 0;
		env_seg->data = 0;
		env_seg->bss = 0;
		env_seg->k = 0;
	}
	else
	{
		env_seg->text = old->text;
		env_seg->data = old->data;
		env_seg->bss = old->bss;
		env_seg->k = old->k;
	}
	return (env_seg);
}

t_count		*ft_segment_32(struct load_command *lc, t_count *old)
{
	struct segment_command		*sg;
	struct section				*s;
	int							j;
	t_count						*env_seg;

	j = 0;
	env_seg = ft_init_count_32(old);
	sg = (struct segment_command *)lc;
	s = (struct section *)
		((char *)sg + sizeof(struct segment_command));
	while (j < sg->nsects)
	{
		if (ft_strcmp((s + j)->sectname, SECT_TEXT) == 0 &&
				ft_strcmp((s + j)->segname, SEG_TEXT) == 0)
			env_seg->text = env_seg->k + 1;
		else if (ft_strcmp((s + j)->sectname, SECT_DATA) == 0 &&
				ft_strcmp((s + j)->segname, SEG_DATA) == 0)
			env_seg->data = env_seg->k + 1;
		else if (ft_strcmp((s + j)->sectname, SECT_BSS) == 0 &&
				ft_strcmp((s + j)->segname, SEG_DATA) == 0)
			env_seg->bss = env_seg->k + 1;
		env_seg->k++;
		j++;
	}
	return (env_seg);
}

void		ft_nm_32(char *ptr, t_symbols **env)
{
	int						ncmds;
	int						i;
	struct mach_header		*header;
	struct load_command		*lc;
	t_count					*seg;

	seg = NULL;
	i = 0;
	header = (struct mach_header *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			seg = ft_segment_32(lc, seg);
		if (lc->cmd == LC_SYMTAB)
		{
			ft_print_32((struct symtab_command *)lc, ptr, env, seg);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	free(seg);
}
