# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:08:32 by jschotte          #+#    #+#              #
#    Updated: 2017/04/20 13:33:42 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm


$(NAME):
		@make -C nm/ fclean && make -C nm

all: $(NAME) 

clean:
		@make -C nm/ clean

fclean: clean
		@make -C nm/ fclean

re: fclean all

.PHONY: clean fclean re
