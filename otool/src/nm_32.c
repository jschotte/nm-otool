/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 16:15:37 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_segment_32(struct load_command *lc, char *ptr, int i, int j)
{
	struct segment_command	*sg;
	struct section			*s;

	sg = (struct segment_command *)lc;
	s = (struct section *)((char *)sg + sizeof(struct segment_command));
	while (j < (int)sg->nsects)
	{
		if (ft_strcmp((s + j)->sectname, SECT_TEXT) == 0 &&
				ft_strcmp((s + j)->segname, SEG_TEXT) == 0)
		{
			ft_printf("%08s\t", ft_itoa_base_str((s + j)->offset + 4096, 16));
			while (i < (s + j)->size)
			{
				if (i % 16 != 0)
					ft_putchar(' ');
				ft_printf("%02s", ft_gettext((ptr + (s + j)->offset)[i]));
				i++;
				if (i % 16 == 0 && i < (s + j)->size)
					ft_printf(" \n%08s\t",
							ft_itoa_base_str((s + j)->offset + i + 4096, 16));
			}
		}
		j++;
	}
}

void		ft_nm_32(char *ptr, char *str)
{
	int						ncmds;
	int						i;
	struct mach_header		*header;
	struct load_command		*lc;

	ft_printf("%s:\nContents of (__TEXT,__text) section\n");
	header = (struct mach_header *)ptr;
	ncmds = header->ncmds;
	i = 0;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			ft_segment_32(lc, ptr, 0, 0);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	ft_putstr(" \n");
}
