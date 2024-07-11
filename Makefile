NAME		= so_long
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX		= ./MLX42
LIBFT	 	= ./library/libft/
GNL			= ./library/get_next_line/
PRINTF		= ./library/printf
HEADERS		= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(GNL) -I $(PRINTF)
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(PRINTF) -lftprintf
SRCS 		= main.c \
				check_path.c \
				collecting.c \
				collision.c \
				controls.c \
				ft_realloc.c \
				graphics.c \
				map_checker.c \
				map_reader.c
OBJS		= $(SRCS:.c=.o)

all: libft gnl printf libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

gnl:
	@$(MAKE) -C $(GNL)

printf:
	@$(MAKE) -C $(PRINTF)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft, gnl, ftprintf



# NAME	:= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LIBMLX	:= ./lib/MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= $(shell find ./src -iname "*.c")
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx