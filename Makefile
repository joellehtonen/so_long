NAME		= so_long
NAME_BONUS	= so_long_bonus
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -g
LIBMLX		= ./MLX42
LIBFT	 	= ./library/libft/
GNL			= ./library/get_next_line/
PRINTF		= ./library/printf/
BONUS_DIR	= ./bonus/
HEADER			= -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(GNL) -I $(PRINTF)
BONUS_HEADER	= -I $(BONUS_DIR) -I $(LIBMLX)/include -I $(LIBFT) -I $(GNL) -I $(PRINTF)
LIBS		= $(LIBMLX)/build/libmlx42.a -g -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(PRINTF) -lftprintf
BASIC_SRCS	= 	main.c \
				check_path.c \
				collision.c \
				controls.c \
				free.c \
				get_images.c \
				graphics.c \
				load_animation.c \
				map_checker.c \
				map_reader.c \
				wall_randomizer.c
BONUS_SRCS	= $(wildcard $(BONUS_DIR)*_bonus.c)
MAIN_OBJS	= $(MAIN_SRCS:.c=.o)
BASIC_OBJS	= $(BASIC_SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

GREEN    	= \033[1;32m
YELLOW      = \033[38;5;220m
CYAN		= \033[0;36m
RESET       = \033[0m

all: libft gnl printf libmlx $(NAME)

bonus: libft gnl printf libmlx $(NAME_BONUS)

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
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(BONUS_HEADER)

$(NAME): $(MAIN_OBJS) $(BASIC_OBJS)
	@$(CC) $(CFLAGS) $(MAIN_OBJS) $(BASIC_OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) CREATED (enjoy)$(RESET)"

$(NAME_BONUS): $(MAIN_OBJS) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $($(MAIN_OBJS)) $(BONUS_OBJS) $(LIBS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) CREATED (enjoy)$(RESET)"

clean:
	@rm -rf $(MAIN_OBJS) $(BASIC_OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(PRINTF) clean
	@echo "$(CYAN)CLEAN COMPLETE$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(PRINTF) fclean
	@echo "$(CYAN)FCLEAN COMPLETE$(RESET)"

re: fclean all
	@echo "$(CYAN)REBUILDING COMPLETE$(RESET)"

.PHONY: all, bonus, clean, fclean, re, libmlx, libft, gnl, ftprintf