/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:52 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/08 16:42:22 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h> //for what?
# include <stdlib.h> //for what? malloc?
# include <stdbool.h> //for what? boolean?
# include <fcntl.h> //for o_rdonly

//define error messages here

# define TILE_SIZE 64
# define PLAYER_WIDTH 32
# define PLAYER HEIGHT 32

typedef struct s_box
{	
	int x;
	int y;
	int width;
	int height;
}	t_box

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

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
	int 	width;
	int 	height;
	int 	collectables;
	int		exit;
	int		start;
	int		move_count;
	char	**map;
	mlx_t	*mlx;
}	t_game;

void ft_controls(t_game *game)

#endif