/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:27:42 by jschotte          #+#    #+#             */
/*   Updated: 2016/03/15 11:01:23 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				**mask_stuff(char *mask, char *wc)
{
	int	maskl;
	int	wcl;

	maskl = ft_strlen(mask) - 1;
	wcl = ft_strlen(wc) - 1;
	while (maskl)
	{
		while (mask[maskl] != 'x' && maskl)
			maskl--;
		if (wcl >= 0)
			mask[maskl--] = wc[wcl--];
		if (wcl == -1 && mask[maskl] == 'x')
			mask[maskl--] = '0';
	}
	ft_strdel(&wc);
	return (ft_strsplit(mask, ' '));
}

static unsigned char	convert_bin(char *s)
{
	int				i;
	unsigned char	bin;
	unsigned char	res;

	res = 0;
	bin = 1;
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		res += (bin * (s[i] - '0'));
		bin *= 2;
		i--;
	}
	return (res);
}

char					*stockbis(char **bin, unsigned int size)
{
	char			*s;
	unsigned char	c;

	s = ft_strnew((int)size);
	size = 0;
	while (bin[size])
	{
		c = convert_bin(bin[size]);
		s[size] = (char)c;
		ft_strdel(&bin[size]);
		size++;
	}
	free(bin);
	s[size] = '\0';
	return (s);
}

void					ft_putwchar(char **bin)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (bin[i])
	{
		c = convert_bin(bin[i]);
		write(1, &c, 1);
		ft_strdel(&bin[i]);
		i++;
	}
	free(bin);
}

char					**mask_unicode(char *wc)
{
	char	*mask;
	char	**bin;

	if (ft_strlen(wc) <= 7)
	{
		mask = ft_strdup("0xxxxxxx");
		bin = mask_stuff(mask, wc);
	}
	else if (ft_strlen(wc) <= 11)
	{
		mask = ft_strdup("110xxxxx 10xxxxxx");
		bin = mask_stuff(mask, wc);
	}
	else if (ft_strlen(wc) <= 16 && ft_strlen(wc) > 11)
	{
		mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
		bin = mask_stuff(mask, wc);
	}
	else
	{
		mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
		bin = mask_stuff(mask, wc);
	}
	ft_strdel(&mask);
	return (bin);
}
