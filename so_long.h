/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:52 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/24 14:05:24 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "library/libft/libft.h"
# include "library/printf/ft_printf.h"
# include "library/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

//define error messages here

# define TILE_SIZE 64
# define MOVE_SIZE (TILE_SIZE * 0.9)
# define MOVE_SPEED 4

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_box
{	
	int x;
	int y;
	int width;
	int height;
}	t_box;

typedef struct s_chicken
{
	int	dying;
	mlx_image_t **animation;
}	t_chicken;

typedef struct s_enemy
{
	int	x;
	int	y;
	int active;
	int	frame;
	int	dying;
	int animation_timer;
	mlx_image_t **animation;
}	t_enemy;

typedef struct s_player
{
	int	x;
	int y;
	int	frame;
	int	dying;
	mlx_image_t **animation;
}	t_player;

typedef struct s_world
{
	mlx_image_t **image;
}	t_world;

typedef struct s_game
{
	//struct s_textures *txts;
	struct s_world *world;
	struct s_player *player;
	struct s_enemy *enemy;
	struct s_chicken *chicken;
	int		frame;
	int		image_content;
	int 	width;
	int 	height;
	int 	collectables;
	int		collected;
	int		exit;
	int		start;
	int		move_count;
	char	**map;
	mlx_t	*mlx;
}	t_game;

void	controls(void *content);
void	flood_fill(t_game *game, int y, int x);
int		*find_start(t_game *game);
int		check_path(t_game *game);
void	collect_stuff(t_game *game);
t_bool	is_wall(t_game *game, int x, int y);
void	collectable_collision(t_game *game, t_box player, int x, int y);
void	exit_collision(t_game *game, t_box player, int x, int y);
t_bool	check_collision(t_box a, t_box b);
void	*ft_realloc(void *old_ptr, size_t new_size);
const char **textures_world(void);
const char **textures_chicken(void);
const char **textures_fox(void);
const char **textures_dog(void);
void	get_images_dog(t_game *game, const char **textures_dog);
void 	get_images_fox(t_game *game, const char **textures_fox);
void 	get_images_chicken(t_game *game, const char **textures_chicken);
void	get_images_world(t_game *game, const char **textures_world);
void	insert_images_to_map(t_game *game, int x, int y);
void 	wall_randomizer(t_game *game, int x, int y);
void	upload_player_and_enemy_animations(t_game *game, int x, int y);
void	update_locations(t_game *game, int x, int y);
void	add_graphics(t_game *game);
void	map_checker(t_game *game);
void	map_reader(t_game *game, char **argv);
void	initialize_variables(t_game *game);
void	initialize_game(t_game *game);
void 	free_and_exit(t_game *game, int error);
void	enemy_appears(t_game *game);
void	update_player_animation(t_game *game, int frame);
//void	idle_animation(t_game *game);

#endif