/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 16:27:38 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_segment_64rev(struct load_command *lc, char *ptr, int i, int j)
{
	struct segment_command_64	*sg;
	struct section_64			*s;

	sg = (struct segment_command_64 *)lc;
	s = (struct section_64 *)((char *)sg + sizeof(struct segment_command_64));
	while (j < (int)sg->nsects)
	{
		if (ft_strcmp((s + j)->sectname, SECT_TEXT) == 0 &&
				ft_strcmp((s + j)->segname, SEG_TEXT) == 0)
		{
			ft_printf("00000001%08s\t", ft_itoa_base_str((s + j)->offset, 16));
			while (i < (s + j)->size)
			{
				if (i % 16 != 0)
					ft_putchar(' ');
				ft_printf("%02s", ft_gettext((ptr + (s + j)->offset)[i]));
				i++;
				if (i % 16 == 0 && i < (s + j)->size)
					ft_printf(" \n00000001%08s\t",
							ft_itoa_base_str((s + j)->offset + i, 16));
			}
		}
		j++;
	}
}

void		ft_nm_64_rev(char *ptr, char *str)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;

	ft_printf("%s:\nContents of (__TEXT,__text) section\n");
	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	i = 0;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			ft_segment_64rev(lc, ptr, 0, 0);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	ft_putstr(" \n");
}
