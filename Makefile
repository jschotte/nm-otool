# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:08:32 by jschotte          #+#    #+#              #
#    Updated: 2017/03/23 12:17:01 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM = ft_nm
NAME_OTOOL = ft_otool

SRC_NM = src_nm/nm.c  src_nm/nm_64.c src_nm/nm_32.c src_nm/env.c
#SRC2_OTOOL = Grace.c

OBJ_NM = nm.o nm_64.o env.o nm_32.o
#OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = "libft/libft.a"

$(NAME_NM):
		@make -C libft/ fclean && make -C libft/
		#gcc $(FLAGS) -c $(SRC_NM) 
		gcc -c $(SRC_NM)
		gcc -o $(NAME_NM) $(OBJ_NM) $(LIB)

all: $(NAME_NM) 

clean:
		@make -C libft/ clean
		rm -rf $(OBJ_NM)

fclean: clean
		@make -C libft/ fclean
		rm -rf $(NAME_NM)

re: fclean all

.PHONY: clean fclean re
