SRC				= src/main.c
OBJ				:= $(SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -Ilibft
NAME			 = push_swap
LIBFT			:= libft.a
LIBFT_SRC		:= libft

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_SRC) all

$(NAME): $(OBJ)
	gcc -o $@ $< $(LIBFT_SRC)/${LIBFT}

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_SRC) clean

fclean:			clean
	$(RM) $(NAME)
	make -C $(LIBFT_SRC) fclean

re:				fclean $(NAME)
	make -C $(LIBFT_SRC) re

.PHONY:			all clean fclean re
