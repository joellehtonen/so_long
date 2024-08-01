/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 12:38:17 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_exit(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->world[5],
		x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->world[6],
		x * TILE_SIZE, y * TILE_SIZE);
}

static void	insert_images_to_map(t_game *game, int x, int y, int i)
{
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				wall_randomizer(game, x, y);
			else if (game->map[y][x] == 'e')
			{
				put_exit(game, x, y);
			}
			else if (game->map[y][x] == 'c')
			{
				upload_chicken_animations(game, x, y, i);
				i++;
			}
			else if (game->map[y][x] == 'p')
			{
				upload_player_animations(game, x, y);
				upload_enemy_animations(game, x, y);
			}
			x++;
		}
		y++;
	}
}

const char	**textures_world(void)
{
	static const char	*textures_world[8];

	textures_world[0] = "textures/green.png";
	textures_world[1] = "textures/wall_1.png";
	textures_world[2] = "textures/wall_2.png";
	textures_world[3] = "textures/wall_3.png";
	textures_world[4] = "textures/wall_4.png";
	textures_world[5] = "textures/exit_green-ish.png";
	textures_world[6] = "textures/exit_yellow.png";
	textures_world[7] = NULL;
	return (textures_world);
}

static void	get_images_world(t_game *game, const char **textures_world)
{
	int				i;
	int				count;
	mlx_texture_t	*texture;

	count = 0;
	while (textures_world[count])
		count++;
	game->world = malloc(sizeof(mlx_image_t *) * count);
	if (game->world == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_world[i]);
		game->world[i] = mlx_texture_to_image(game->mlx, texture);
		if (!game->world[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->world[i], TILE_SIZE * 1, TILE_SIZE * 1);
		mlx_delete_texture(texture);
		i++;
	}
	mlx_resize_image(game->world[0], TILE_SIZE * game->width,
		TILE_SIZE * game->height);
}

void	add_graphics(t_game *game)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	get_images_world(game, textures_world());
	get_images_chicken(game, textures_chicken());
	get_images_fox(game, textures_fox());
	get_images_fox_reverse(game, textures_fox_reverse());
	get_images_dog(game, textures_dog());
	get_images_dog_reverse(game, textures_dog_reverse());
	mlx_image_to_window(game->mlx, game->world[0], 0, 0);
	insert_images_to_map(game, x, y, i);
}
