SRC				= src/main.c \
				  src/parse.c \
				  src/stack.c 
OBJ				:= $(SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -Iincludes
NAME			 = push_swap
LIBFT			:= libft.a
LIBFT_SRC		:= libft

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_SRC) all

$(NAME): $(OBJ)
	gcc -o $@ $(OBJ) $(LIBFT_SRC)/${LIBFT}

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_SRC) clean

fclean:			clean
	$(RM) $(NAME)
	make -C $(LIBFT_SRC) fclean

re: fclean $(NAME)
	make -C $(LIBFT_SRC) re

.PHONY:			all clean fclean re
