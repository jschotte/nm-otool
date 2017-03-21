/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:51:08 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/21 11:03:08 by jschotte         ###   ########.fr       */
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

void		ft_nm_64(char *ptr, t_symbols *env);

void		ft_print_symbols(t_symbols *env);
t_symbols	*ft_init_env();
t_symbols	*ft_create_elem(char *name, char *value, char c);
void		ft_pushback(t_symbols *env, t_symbols *new);

#endif
