SRC				= src/main.c \
				  src/parse.c \
				  src/stack.c \
				  src/stack_algo.c \
				  src/algo_utils.c \
				  src/utils.c \
				  src/commands/sa.c \
				  src/commands/sb.c \
				  src/commands/ss.c \
				  src/commands/pa.c \
				  src/commands/pb.c \
				  src/commands/ra.c	\
				  src/commands/rb.c \
				  src/commands/rr.c

OBJ				:= $(SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -Iincludes -g
NAME			 = push_swap
LIBFT			:= libft.a
LIBFT_SRC		:= libft

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_SRC) all

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $@ $(OBJ) $(LIBFT_SRC)/${LIBFT}

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_SRC) clean

fclean:			clean
	$(RM) $(NAME)
	make -C $(LIBFT_SRC) fclean

re: fclean $(LIBFT) $(NAME) 

.PHONY:			all clean fclean re
