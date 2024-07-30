/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 15:46:22 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_exit(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->world[5], x * TILE_SIZE, y * TILE_SIZE);
	mlx_image_to_window(game->mlx, game->world[6], x * TILE_SIZE, y * TILE_SIZE);
}

static void	update_locations(t_game *game, int x, int y)
{
	game->player->x = x * TILE_SIZE;
	game->player->y = y * TILE_SIZE;
	game->enemy->x = game->player->x;
	game->enemy->y = game->player->y;
}

static void	get_images_world(t_game *game, const char **textures_world)
{
	int				i;
	int				count;
	mlx_texture_t	*texture;

	count = 0;
	while(textures_world[count])
		count++;
	game->world = malloc(sizeof(mlx_image_t *) * count);
	if (game->world == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_world[i]);
		game->world[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->world[i], TILE_SIZE * 1, TILE_SIZE * 1);
		mlx_delete_texture(texture);
		i++;
	}
}

void	insert_images_to_map(t_game *game, int x, int y, int i)
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
				put_exit(x, y);
			}
			else if (game->map[y][x] == 'c')
			{
				upload_chicken_animations(game, x, y, i);
				i++;
			}
			else if (game->map[y][x] == 'p')
			{
				upload_player_and_enemy_animations(game, x, y);
				update_locations(game, x, y);
			}
			x++;
		}
		y++;
	}
}

void	add_graphics(t_game *game)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	get_images_world(game, textures_world());
	mlx_resize_image(game->world[0], TILE_SIZE * game->width, 
		TILE_SIZE * game->height);
	get_images_chicken(game, textures_chicken());
	get_images_fox(game, textures_fox());
	get_images_dog(game, textures_dog());
	get_images_fox_reverse(game, textures_fox_reverse());
	get_images_dog_reverse(game, textures_dog_reverse());
	mlx_image_to_window(game->mlx, game->world[0], 0, 0);
	insert_images_to_map(game, x, y, i);
}
