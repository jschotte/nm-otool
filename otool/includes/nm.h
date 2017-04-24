/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:51:08 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/24 10:41:30 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"
# define MAGIC_ARCH 0x72613C21

typedef struct			s_fat
{
	char				*ptr;
	char				*cpuname;
	struct s_fat		*next;
}						t_fat;

int						ft_nm(char *ptr, char *str);
void					ft_nm_64(char *ptr);
void					ft_nm_32(char *ptr);
void					ft_fat(char *ptr, char *str);
void					ft_lib(char *ptr, char *str);

struct mach_header		*swap_mach_header(struct mach_header *header);
struct load_command		*swap_lc(struct load_command *lc);
struct mach_header_64	*swap_mach_heade_64(struct mach_header_64 *header);
uint32_t				swap_fat_header(uint32_t value);
uint32_t				swapint32(uint32_t x);

void					*ft_exit(char *error);

char					*ft_getcputype(struct fat_arch *arch);
t_fat					*ft_init_fat(void);
t_fat					*ft_create_elem_fat(char *ptr, char *cpuname);
void					ft_pushback_fat(t_fat **env, t_fat *new);
void					freefat(t_fat **fat);
void					ft_gettext(unsigned int nb);

#endif
