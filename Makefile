SRC				= main.c \
				  parse.c \
				  stack.c \
				  stack_algo.c \
				  algo_op.c \
				  utils.c \
				  sa.c \
				  sb.c \
				  ss.c \
				  pa.c \
				  pb.c \
				  ra.c	\
				  rb.c \
				  rr.c \
				  rra.c \
				  rrb.c \
				  rrr.c \
				  algo_utils.c   \
				  algo_pswap.c	 \
				  algo_spec.c

OBJ				:= $(SRC:.c=.o)
CFLAGS			:= -Wall -Wextra -Werror -Ilibft -fPIE -g
NAME			 = push_swap
LIBFT			:= libft.a
LIBFT_SRC		:= libft

all: $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	make -C $(LIBFT_SRC) all

$(NAME): $(OBJ)
	@gcc $(CFLAGS) -o $@ $(OBJ) $(LIBFT_SRC)/${LIBFT}

clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_SRC) clean

fclean:			clean
	$(RM) $(NAME)
	make -C $(LIBFT_SRC) fclean

re: fclean $(LIBFT) $(NAME) 

.PHONY:			all clean fclean re
