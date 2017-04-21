/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:51:08 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/21 10:15:38 by jschotte         ###   ########.fr       */
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

typedef struct			s_symbols
{
	char				*hexvalue;
	char				type;
	char				*name;
	struct s_symbols	*next;
}						t_symbols;

typedef struct			s_fat
{
	char				*ptr;
	char				*cpuname;
	struct s_fat		*next;
}						t_fat;

typedef struct			s_count
{
	unsigned int text;
	unsigned int data;
	unsigned int bss;
	unsigned int k;
}						t_count;

int						ft_nm(char *ptr, char *str, t_symbols *env);
void					ft_nm_64(char *ptr, t_symbols **env);
void					ft_nm_32(char *ptr, t_symbols **env);
void					ft_nm_64_rev(char *ptr, t_symbols **env);
void					ft_nm_32_rev(char *ptr, t_symbols **env);
void					ft_fat(char *ptr, t_symbols **env, char *str);
void					ft_lib(char *ptr, t_symbols **env, char *str);

struct mach_header		*swap_mach_header(struct mach_header *header);
struct load_command		*swap_lc(struct load_command *lc);
struct mach_header_64	*swap_mach_heade_64(struct mach_header_64 *header);
uint32_t				swap_fat_header(uint32_t value);
uint32_t				swapint32(uint32_t x);

char					*ft_get_value(long long value, int nb);
char					ft_get_type(int value, int sect);
char					ft_get_type_v2(unsigned char type, unsigned char sect,
	unsigned long value, t_count *seg);
void					ft_print_symbols(t_symbols **env);
t_symbols				*ft_init_env(t_symbols *env);
t_symbols				*ft_create_elem(char *name, char *value, char c);
void					ft_pushback(t_symbols **env, t_symbols *new);
t_symbols				*ft_sort_list(t_symbols *lst);
void					*ft_exit(char *error);

char					*ft_getcputype(struct fat_arch *arch);
t_fat					*ft_init_fat(void);
t_fat					*ft_create_elem_fat(char *ptr, char *cpuname);
void					ft_pushback_fat(t_fat **env, t_fat *new);
void					freefat(t_fat **fat);

#endif
