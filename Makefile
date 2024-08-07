NAME		= so_long
NAME_BONUS	= so_long_bonus
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -g
MLX			= ./MLX42
LIBFT	 	= ./library/libft/
GNL			= ./library/get_next_line/
PRINTF		= ./library/printf/
SRCS_DIR 	= ./sources/
BONUS_DIR	= ./bonus/
HEADER			= -I ./include -I $(MLX)/include -I $(LIBFT) -I $(GNL) -I $(PRINTF)
BONUS_HEADER	= -I $(BONUS_DIR) -I $(MLX)/include -I $(LIBFT) -I $(GNL) -I $(PRINTF)
LIBS		= $(MLX)/build/libmlx42.a -g -ldl -lglfw -pthread -lm -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(PRINTF) -lftprintf
BASIC_SRCS	= 	$(SRCS_DIR)main.c \
				$(SRCS_DIR)check_path.c \
				$(SRCS_DIR)collision.c \
				$(SRCS_DIR)controls.c \
				$(SRCS_DIR)free.c \
				$(SRCS_DIR)get_images.c \
				$(SRCS_DIR)graphics.c \
				$(SRCS_DIR)load_animation.c \
				$(SRCS_DIR)map_checker.c \
				$(SRCS_DIR)map_reader.c \
				$(SRCS_DIR)wall_randomizer.c
BONUS_SRCS	=	$(BONUS_DIR)main_bonus.c \
				$(BONUS_DIR)animation_bonus.c \
				$(BONUS_DIR)check_path_bonus.c \
				$(BONUS_DIR)collision_bonus.c \
				$(BONUS_DIR)controls_bonus.c \
				$(BONUS_DIR)enemy_animation_bonus.c \
				$(BONUS_DIR)enemy_bonus.c \
				$(BONUS_DIR)enemy_death_bonus.c \
				$(BONUS_DIR)free_bonus.c \
				$(BONUS_DIR)get_images_bonus.c \
				$(BONUS_DIR)graphics_bonus.c \
				$(BONUS_DIR)load_animation_bonus.c \
				$(BONUS_DIR)map_checker_bonus.c \
				$(BONUS_DIR)map_reader_bonus.c \
				$(BONUS_DIR)texture_names_bonus.c \
				$(BONUS_DIR)wall_randomizer_bonus.c \
				$(BONUS_DIR)write_moves_bonus.c
BASIC_OBJS	= $(BASIC_SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

GREEN    	= \033[1;32m
YELLOW      = \033[38;5;220m
CYAN		= \033[0;36m
RESET       = \033[0m

all: libft gnl printf mlx $(NAME)

bonus: libft gnl printf mlx $(NAME_BONUS)

mlx: $(MLX)/build/libmlx42.a

$(MLX)/build/libmlx42.a:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	@echo "$(GREEN)MLX42 BUILT$(RESET)"

libft: $(LIBFT)/libft.a

$(LIBFT)/libft.a:
	@echo "$(YELLOW)BUILDING LIBFT (please be patient)$(RESET)"
	@$(MAKE) -C $(LIBFT)
	@echo "$(GREEN)LIBFT BUILT$(RESET)"

gnl: $(GNL)/libgnl.a

$(GNL)/libgnl.a:
	@$(MAKE) -C $(GNL)
	@echo "$(GREEN)GNL BUILT$(RESET)"

printf: $(PRINTF)/libftprintf.a

$(PRINTF)/libftprintf.a:
	@$(MAKE) -C $(PRINTF)
	@echo "$(GREEN)PRINTF BUILT$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

$(BONUS_DIR)%.o: $(BONUS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(BONUS_HEADER)

$(NAME): $(BASIC_OBJS)
	@$(CC) $(CFLAGS) $(MAIN_OBJS) $(BASIC_OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) CREATED (enjoy)$(RESET)"

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $($(MAIN_OBJS)) $(BONUS_OBJS) $(LIBS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) CREATED (enjoy)$(RESET)"

clean:
	@rm -rf $(BASIC_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(GNL) clean
	@$(MAKE) -C $(PRINTF) clean
	@echo "$(CYAN)CLEAN COMPLETE$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(MLX)/build/libmlx42.a
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(GNL) fclean
	@$(MAKE) -C $(PRINTF) fclean
	@echo "$(CYAN)FCLEAN COMPLETE$(RESET)"

re: fclean all
	@echo "$(CYAN)REBUILDING COMPLETE$(RESET)"

.PHONY: all bonus clean fclean re libmlx libft gnl printf
