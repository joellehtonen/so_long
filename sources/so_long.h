/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:52 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/08 15:46:03 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define SUCCESS 0
# define FAILURE 1

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

typedef struct s_player
{
	int			x;
	int			y;
	mlx_image_t	**animation;
}	t_player;

typedef struct s_game
{
	struct s_player		*player;
	struct s_chicken	*chicken;
	mlx_image_t			**world;
	mlx_texture_t		*text;
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
void		check_map_format(t_game *game, char *argv);
void		get_map_size(t_game *game, char **argv);
void		map_reader(t_game *game, char **argv);
void		map_checker(t_game *game);
int			check_path(t_game *game, int x, int y);
void		add_graphics(t_game *game);
void		wall_randomizer(t_game *game, int x, int y);
void		display_error(t_game *game, char *string);
void		free_and_exit(t_game *game, int error);
void		free_map(t_game *game);
// gameplay functions
void		controls(void *content);
void		collect_stuff(t_game *game);
void		collectable_collision(t_game *game, t_box player, int x, int y);
void		exit_collision(t_game *game, t_box player, int x, int y);
int			check_collision(t_box a, t_box b);
int			is_wall(t_game *game, int x, int y);
// texture functions
const char	**textures_world(void);
// animation functions
void		get_images_fox(t_game *game);
void		get_images_chicken(t_game *game);
void		upload_player_animations(t_game *game, int x, int y);
void		upload_chicken_animations(t_game *game, int x, int y, int number);
void		update_player_animation(t_game *game, int frame);
void		update_chicken_animation(t_game *game, int number);

#endif