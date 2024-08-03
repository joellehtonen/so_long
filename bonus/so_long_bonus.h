/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:52 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/03 12:06:25 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"
# include "../library/printf/ft_printf.h"
# include "../library/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

# define TILE_SIZE 64
# define MOVE_SIZE 56
# define MOVE_SPEED 4
# define MAX_HEIGHT 2100
# define MAX_WIDTH 3800

typedef struct s_box
{	
	int	x;
	int	y;
	int	width;
	int	height;
}	t_box;

typedef struct s_chicken
{
	mlx_image_t	**animation;
}	t_chicken;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			active;
	int			frame;
	int			dying;
	int			animation_timer;
	int			move_count;
	int			left;
	mlx_image_t	**animation;
	mlx_image_t	**rev_anim;
}	t_enemy;

typedef struct s_player
{
	int			x;
	int			y;
	int			frame;
	int			left;
	mlx_image_t	**animation;
	mlx_image_t	**rev_anim;
}	t_player;

typedef struct s_game
{
	struct s_player		*player;
	struct s_enemy		*enemy;
	struct s_chicken	*chicken;
	mlx_image_t			**world;
	mlx_image_t			*moves;
	mlx_t				*mlx;
	char				**map;
	int					frame;
	int					width;
	int					height;
	int					collectables;
	int					collected;
	int					exit;
	int					start;
	int					move_count;
}	t_game;

// initialization and freeing functions
void		initialize_game(t_game *game);
void		check_map_format(t_game *game, char *argv);
void		get_map_size(t_game *game, char **argv);
void		map_reader(t_game *game, char **argv);
void		map_checker(t_game *game);
int			check_path(t_game *game, int x, int y);
void		add_graphics(t_game *game);
void		wall_randomizer(t_game *game, int x, int y);
void		display_error(t_game *game, char *string);
void		free_and_exit(t_game *game, int error);
// gameplay functions
void		controls(void *content);
void		collect_stuff(t_game *game);
void		collectable_collision(t_game *game, t_box player, int x, int y);
void		exit_collision(t_game *game, t_box player, int x, int y);
int			check_collision(t_box a, t_box b);
int			is_wall(t_game *game, int x, int y);
void		write_moves_to_window(t_game *game);
// texture functions
const char	**textures_world(void);
const char	**textures_chicken(void);
const char	**textures_fox(void);
const char	**textures_fox_reverse(void);
const char	**textures_dog(void);
const char	**textures_dog_reverse(void);
// animation functions
void		get_images_fox(t_game *game, const char **textures_fox);
void		get_images_fox_reverse(t_game *game,
				const char **textures_fox_reverse);
void		get_images_dog(t_game *game, const char **textures_dog);
void		get_images_dog_reverse(t_game *game,
				const char **textures_dog_reverse);
void		get_images_chicken(t_game *game, const char **textures_chicken);
void		upload_player_animations(t_game *game, int x, int y);
void		upload_chicken_animations(t_game *game, int x, int y, int number);
void		upload_enemy_animations(t_game *game, int x, int y);
void		player_run_animation(t_game *game, int frame);
void		player_idle_animation(t_game *game);
void		chicken_idle_animation(t_game *game);
void		chicken_dies_animation(t_game *game, int number);
// enemy functions
void		enemy_appears(t_game *game);
void		enemy_dies(t_game *game);

#endif