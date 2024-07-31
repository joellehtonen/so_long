NAME		= so_long
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -g
LIBMLX		= ./MLX42
LIBFT	 	= ./library/libft/
GNL			= ./library/get_next_line/
PRINTF		= ./library/printf
HEADERS		= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(GNL) -I $(PRINTF)
LIBS		= $(LIBMLX)/build/libmlx42.a -g -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(PRINTF) -lftprintf
SRCS 		= main.c \
				free.c \
				check_path.c \
				collision.c \
				controls.c \
				graphics.c \
				get_images.c \
				map_checker.c \
				map_reader.c \
				animation.c \
				load_animation.c \
				wall_randomizer.c \
				texture_names.c \
				enemy.c \
				enemy_death.c \
				enemy_animation.c \
				write_moves.c
OBJS		= $(SRCS:.c=.o)

GREEN    	= \033[1;32m
YELLOW      = \033[38;5;220m
CYAN		= \033[0;36m
RESET       = \033[0m

all: libft gnl printf libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "$(GREEN)MLX42 BUILT$(RESET)"

libft:
	@echo "$(YELLOW)BUILDING LIBFT (please be patient)$(RESET)"
	@$(MAKE) -C $(LIBFT)
	@echo "$(GREEN)LIBFT BUILT$(RESET)"

gnl:
	@$(MAKE) -C $(GNL)
	@echo "$(GREEN)GNL BUILT$(RESET)"

printf:
	@$(MAKE) -C $(PRINTF)
	@echo "$(GREEN)PRINTF BUILT$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) CREATED (enjoy)$(RESET)"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(PRINTF) clean
	@echo "$(CYAN)CLEAN COMPLETE$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(PRINTF) fclean
	@echo "$(CYAN)FCLEAN COMPLETE$(RESET)"

re: fclean all
	@echo "$(CYAN)REBUILDING COMPLETE$(RESET)"

.PHONY: all, clean, fclean, re, libmlx, libft, gnl, ftprintf