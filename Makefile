.PHONY: all, clean, fclean, re

NAME = fdf

SRCS = main.c
OBJS = $(SRCS:.c=.o)

INCLUDEMLX = -I /usr/local/include
LINKS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror
INCLUDES = fdf.h
LIB_NAME = ./libft/libft.a

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I $(INCLUDES)

all : $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	clang $(INCLUDEMLX) $(FLAGS) $(LINKS) $(LIB_NAME) $^ -o $@

clean :
	@/bin/rm -f $(OBJS)
	@make clean -C libft

fclean : clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re : fclean all

