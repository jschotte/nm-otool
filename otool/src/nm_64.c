/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:55:38 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/24 10:40:41 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void		ft_gettext(unsigned int nb)
{
	char	*str;

	if (nb <= 2147483648)
		str = ft_itoa_base_str(nb, 16);
	else
		str = ft_itoa_base_str(nb - 4294967040, 16);
	ft_printf("%02s", str);
	free(str);
}

void		ft_print_hex(unsigned int nb)
{
	char	*str;

	str = ft_itoa_base_str(nb, 16);
	ft_printf("00000001%08s\t", str);
	free(str);
}

void		ft_print_hex2(unsigned int nb)
{
	char	*str;

	str = ft_itoa_base_str(nb, 16);
	ft_printf(" \n00000001%08s\t", str);
	free(str);
}

void		ft_segment(struct load_command *lc, char *ptr, int i, int j)
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
			ft_print_hex((s + j)->offset);
			while ((uint64_t)i < (s + j)->size)
			{
				if (i % 16 != 0)
					ft_putchar(' ');
				ft_gettext((ptr + (s + j)->offset)[i]);
				i++;
				if (i % 16 == 0 && (uint64_t)i < (s + j)->size)
					ft_print_hex2((s + j)->offset + i);
			}
		}
		j++;
	}
}

void		ft_nm_64(char *ptr)
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
			ft_segment(lc, ptr, 0, 0);
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	ft_putstr(" \n");
}
