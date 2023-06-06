#Project name
NAME=libftprintf.a
#Compiler
CC=cc
#Compiler flags
CC_FLAGS= -Wall -Werror -Wextra
#Includes
INCLUDES=./libftprintf.h
#Source files
SRC=ft_printf.c hex.c unsigned.c itoa_base.c
#Object files
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CC_FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf libftprintf.a

re: fclean all