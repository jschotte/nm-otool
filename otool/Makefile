# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:08:32 by jschotte          #+#    #+#              #
#    Updated: 2017/04/21 16:25:12 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_otool

SRC = src/nm.c  src/nm_64.c src/nm_32.c src/fat.c src/lib.c \
		 src/nm_64rev.c src/nm_32rev.c src/utilsfat.c src/swap.c

OBJ = nm.o nm_64.o nm_64rev.o nm_32rev.o swap.o nm_32.o fat.o utilsfat.o lib.o

FLAGS = -Wall -Wextra -Werror

LIB = "libft/libft.a"

$(NAME):
		@make -C libft/ fclean && make -C libft/
		#gcc $(FLAGS) -c $(SRC) 
		gcc -c $(SRC) 
		gcc -o $(NAME) $(OBJ) $(LIB)

all: $(NAME) 

clean:
		@make -C libft/ clean
		rm -rf $(OBJ)

fclean: clean
		@make -C libft/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
