/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:50:12 by jschotte          #+#    #+#             */
/*   Updated: 2017/04/24 10:41:40 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

int		ft_error(char *error, char *str)
{
	ft_printf("%s: %s\n", str, error);
	return (1);
}

int		ft_nm(char *ptr, char *str)
{
	int			magic_number;

	magic_number = *(int *)ptr;
	if (magic_number == (int)MH_MAGIC_64 || magic_number == (int)MH_CIGAM_64)
		ft_nm_64(ptr);
	else if (magic_number == (int)MH_MAGIC || magic_number == (int)MH_CIGAM)
		ft_nm_32(ptr);
	else if (magic_number == (int)FAT_MAGIC)
		ft_fat(ptr, str);
	else if (magic_number == (int)FAT_CIGAM)
		ft_fat(ptr, str);
	else if (magic_number == (int)MAGIC_ARCH)
		ft_lib(ptr, str);
	else
		return (ft_error("The file was not a valid object file.", str));
	return (0);
}

int		ft_check_file(char *str)
{
	int			fd;
	char		*ptr;
	struct stat	buf;
	int			ret;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (ft_error("File not found", str));
	if (fstat(fd, &buf) < 0)
		return (ft_error("Fstat error", str));
	if (S_ISDIR(buf.st_mode))
		return (ft_error("File is a directory", str));
	if ((ptr = mmap(0, buf.st_size, PROT_READ,
					MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (ft_error("Mmap error", str));
	ret = ft_nm(ptr, str);
	if (munmap(ptr, buf.st_size) < 0)
		return (ft_error("Munmap error", str));
	return (ret);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		return (ft_check_file("./a.out"));
	else if (ac == 2)
		return (ft_check_file(av[1]));
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
