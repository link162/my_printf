NAME		=	libftprintf.a

LIB			=	libft/
LIB_N		=	libft.a

SRC_D		=	src/
SRC			=	$(SRC_D)ft_printf.c \
				$(SRC_D)parsing.c \
				$(SRC_D)parsing2.c \
				$(SRC_D)print_int.c \
				$(SRC_D)prepare_to_print.c \
				$(SRC_D)print_char_str.c \
				$(SRC_D)print_hex.c \
				$(SRC_D)print_double.c \
				$(SRC_D)print_octal.c

OBJ_D		=	obj/
OBJ			=	$(addprefix $(OBJ_D), $(SRC:.c=.o))

INCLUDE		=	-I includes/
CFLAGS		=	-Wall -Wextra -Werror
C			=	gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@cp $(LIB)$(LIB_N) $(NAME)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc -Wall -Werror -Wextra main.c libftprintf.a -I includes
	@echo "$(NAME) create"

$(OBJ): | $(OBJ_D)

$(OBJ_D):
	@mkdir -p $(OBJ_D)$(SRC_D)

$(OBJ_D)%.o: %.c
	@$(C) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "object files was deleted"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -rf $(OBJ_D)
	@rm -rf a.out

re: fclean all

.PHONY: all clean fclean re
