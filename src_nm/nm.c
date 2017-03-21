/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:50:12 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/21 10:57:01 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

int		ft_error(char *error)
{
	ft_printf("%s\n", error);
	return (0);
}

void	ft_nm(char *ptr)
{
	int			magic_number;
	t_symbols	*env;

	env = ft_init_env();
	magic_number = *(int *)ptr;
	if (magic_number == MH_MAGIC_64)
		ft_nm_64(ptr, env);
	else
		ft_error("Not a valid file");
	ft_print_symbols(env);
	free(env);
}

int		ft_check_file(char *str)
{
	int			fd;
	char		*ptr;
	struct stat	buf;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (ft_error("File not found :("));
	if (fstat(fd, &buf) < 0)
		return (ft_error("Fstat error"));
	if (S_ISDIR(buf.st_mode))
		return (ft_error("File is a directory"));
	if ((ptr = mmap(0, buf.st_size, PROT_READ,
					MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ft_error("Mmap error"));
	
	ft_nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (ft_error("Munmap error"));
	return (1);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		ft_check_file("./a.out");
	else if (ac == 2)
		ft_check_file(av[1]);
	else
	{
		while (i < ac)
		{
			ft_printf("\n%s: ", av[i]);
			ft_check_file(av[i]);
			i++;
		}
	}
	return (0);
}
