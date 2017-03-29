# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:08:32 by jschotte          #+#    #+#              #
#    Updated: 2017/03/29 20:08:04 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

SRC = src/nm.c  src/nm_64.c src/nm_32.c src/env.c src/type.c \
		 src/value.c src/lst.c

OBJ = nm.o nm_64.o env.o nm_32.o type.o value.o lst.o

FLAGS = -Wall -Wextra -Werror

LIB = "libft/libft.a"

$(NAME):
		@make -C libft/ fclean && make -C libft/
		#gcc $(FLAGS) -c $(SRC) 
		gcc -c $(SRC)
		gcc -o $(NAME) $(OBJ) $(LIB)
		mv $(NAME) ..

all: $(NAME) 

clean:
		@make -C libft/ clean
		rm -rf $(OBJ)

fclean: clean
		@make -C libft/ fclean
		rm -rf ../$(NAME)

re: fclean all

.PHONY: clean fclean re
