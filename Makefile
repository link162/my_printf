# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 12:22:16 by ybuhai            #+#    #+#              #
#    Updated: 2018/12/11 18:01:02 by ybuhai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
FLAGS = -Wall -Wextra -Werror
FILES = main.c ft_printf.c parsing.c
OBJECT = $(FILES:.c=.o)

$(NAME) : $(OBJECT)
	@gcc $(FLAGS) -c $(FILES)
	@gcc -o $(NAME) $(OBJECT)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean clean re
