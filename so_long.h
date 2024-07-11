/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:52 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 15:25:26 by jlehtone         ###   ########.fr       */
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

//define error messages here

# define TILE_SIZE 32

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

typedef struct s_player
{

}	t_player;

typedef struct s_textures
{
	mlx_texture_t *ground;
	mlx_texture_t *wall;
	mlx_texture_t *exit;
	mlx_texture_t *player;
	mlx_texture_t *collect;
}	t_textures;

typedef struct s_images
{
	mlx_image_t *ground;
	mlx_image_t *wall;
	mlx_image_t *exit;
	mlx_image_t *player;
	mlx_image_t *collect;
}	t_images;

typedef struct s_game
{
	struct s_textures *txts;
	struct s_images *imgs;
	struct s_player player;
	int 	width;
	int 	height;
	int 	collectables;
	int		exit;
	int		start;
	int		move_count;
	char	**map;
	mlx_t	*mlx;
}	t_game;

void	controls(void *content);
void	flood_fill(t_game *game, int y, int x);
int		*find_start(t_game *game);
t_bool	check_path(t_game *game);
void	reach_exit(t_game *game, int position_x, int position_y);
void	delete_collected(t_game *game, int x, int y);
void	collect_stuff(t_game *game);
t_bool	is_wall(t_game *game, int x, int y);
t_bool	is_collectable(t_game *game, int x, int y);
t_bool	is_exit(t_game *game, int x, int y);
t_bool	check_collision(t_box a, t_box b);
void 	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	add_graphics(t_game *game);
int		check_walls_horizontal(t_game *game);
int		check_walls_vertical(t_game *game);
int		check_rectangular(t_game *game);
int		check_count(t_game *game);
void	map_checker(t_game *game);
void	add_line(t_game *game, char *line);
int		map_reader(t_game *game, char **argv);
void	initialize_variables(t_game *game);
void 	free_and_exit(t_game *game, int error);

#endif