# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 12:22:16 by ybuhai            #+#    #+#              #
#    Updated: 2018/12/28 09:24:05 by ybuhai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
FLAGS = -Wall -Wextra -Werror
FILES = main.c ft_printf.c parsing.c parsing2.c print_int.c prepare_to_print.c\
		print_char_str.c print_hex.c print_double.c
OBJECT = $(FILES:.c=.o)

$(NAME) : $(OBJECT)
	@ gcc -g3 -O0 -c $(FILES)
	@ gcc -g3 -O0 -o $(NAME) $(OBJECT)
	@ rm -rf $(OBJECT)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean clean re
