#Project name
NAME=libftprintf.a
#Compiler
CC=cc
#Compiler flags
CC_FLAGS= -Wall -Werror -Wextra
#Includes
INCLUDES=./ft_printf.h
#Bonus Includes
B_INCLUDES=./bonus/ft_printf_bonus.h
#Source files
SRC = ft_printf.c num_printers.c handlers.c checkers.c
#Bonus source files
B_SRC = ./bonus/ft_printf_bonus.c ./bonus/num_printers_bonus.c ./bonus/handlers_bonus.c ./bonus/checkers_bonus.c
#Object files
OBJ=$(SRC:.c=.o)
#Bonus object files
B_OBJ=$(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)

bonus: $(B_OBJ)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@
	ar -rcs $(NAME) $@

clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -rf libftprintf.a

re: fclean all

norm:
	-@norminette

.PHONY: all clean fclean re norm bonus