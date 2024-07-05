NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SOURCES = \
			ft_character.c \
			ft_hexa.c \
			ft_integer.c \
			ft_printf.c \
			ft_string.c \
			ft_unsigned.c \
			ft_void_pointer.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re