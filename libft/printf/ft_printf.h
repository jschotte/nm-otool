/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:52:52 by jschotte          #+#    #+#             */
/*   Updated: 2017/03/14 11:48:13 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_env
{
	va_list		ap;
	int			i;
	int			fail;
	int			diese;
	int			moins;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			precision;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			ret;
	int			punct;
	int			size;
}				t_env;

int				ft_printf(char *format, ...);
void			flag_diese(char *format, t_env *env);
void			flag_moins(char *format, t_env *env);
void			flag_plus(char *format, t_env *env);
void			flag_space(char *format, t_env *env);
void			flag_zero(char *format, t_env *env);
void			flag_width(char *format, t_env *env);
void			flag_precision(char *format, t_env *env);
void			flag_length(char *format, t_env *env);
void			ft_conv(char *format, t_env *env);
void			conv_d(char *format, t_env *env);
void			conv_c(t_env *env, char *format);
void			conv_s(t_env *env);
void			conv_pourcent(t_env *env);
void			conv_u(t_env *env, char *format);
void			conv_x(t_env *env, char *format);
char			*ft_itoa_base_unsigned(unsigned long long value, int base);
void			conv_o(t_env *env, char *format);
void			ft_put_zero(int k, t_env *env);
void			ft_put_space(int k, t_env *env);
void			ft_putnbr_u(unsigned long long value);
int				ft_putnstr(char*s, t_env *env, int i);
void			conv_p(t_env *env);
char			*ft_putstrl(char *s);
char			*ft_itoa_base_long(long long value, int base);
void			ft_putchar_nb(char c, int i);
void			wrong_conv(char *format, t_env *env);
void			conv_bigc(t_env *env);
char			**mask_unicode(char *wc);
void			ft_putwchar(char **bin);
void			conv_ws(t_env *env, char *format);
char			*stockbis(char **bin, unsigned int size);
char			*ft_itoa_base_long(long long value, int base);

#endif
