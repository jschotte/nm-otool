/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:51:08 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/29 20:44:02 by jschotte         ###   ########.fr       */
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
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct	s_symbols
{
	char				*hexvalue;
	char				type;
	char				*name;
	struct s_symbols	*next;
}				t_symbols;

typedef struct	s_count
{
	unsigned int text;
	unsigned int data;
	unsigned int bss;
	unsigned int k;
}				t_count;

void		ft_nm_64(char *ptr, t_symbols **env);
void		ft_nm_32(char *ptr, t_symbols **env);

char		*ft_get_value(long long value, int nb);
char		ft_get_type(int value, int sect);
char		ft_get_type_v2(unsigned char type, unsigned char sect, unsigned long value, t_count *seg);
void		ft_print_symbols(t_symbols **env);
t_symbols	*ft_init_env();
t_symbols	*ft_create_elem(char *name, char *value, char c);
void		ft_pushback(t_symbols **env, t_symbols *new);
t_symbols	*ft_sort_list(t_symbols *lst);
void		ft_exit(char *error);

#endif
