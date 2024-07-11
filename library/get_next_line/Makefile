NAME 	= libgnl.a
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= get_next_line.c get_next_line_utils.c
OBJS 	= $(SRCS:.c=.o)
HEADERS = get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re