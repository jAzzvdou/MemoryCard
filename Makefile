NAME	=	memory

SRCS	=	main.c           \
		memorycard.c      \
		memnode.c          \
		memlist.c           \
		memorycard_utils.c   \
		memorycard_cleaners.c \
		types_functions.c      \


OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<

val: re
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./memory

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
