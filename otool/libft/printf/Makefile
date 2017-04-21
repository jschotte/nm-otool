# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  jschotte<marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/06 20:29:39 by jschotte          #+#    #+#              #
#    Updated: 2017/03/14 11:50:16 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a

SRC = ft_printf.c \
	  ft_flags.c  \
	  ft_flags_2.c \
	  ft_conv.c \
	  conv_d.c \
	  conv_c.c \
	  conv_s.c \
	  conv_pourcent.c \
	  conv_u.c \
	  conv_x.c \
	  ft_itoa_base.c \
	  conv_o.c \
	  utils.c \
	  conv_p.c \
	  wrong_conv.c \
	  unicode.c \
	  conv_ws.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):
	@$(CC) -c $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
