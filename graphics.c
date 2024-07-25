/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 15:48:51 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_locations(t_game *game, int x, int y)
{
	game->player->x = x * TILE_SIZE;
	game->player->y = y * TILE_SIZE;
	game->enemy->x = game->player->x;
	game->enemy->y = game->player->y;
}

void get_images_world(t_game *game, const char **textures_world)
{
	int	i;
	int image_count;
	mlx_texture_t *texture;

	image_count = 0;
	while(textures_world[image_count])
		image_count++;
	game->world->image = malloc(sizeof(mlx_image_t *) * image_count);
	if (game->world->image == NULL)
	{
		//error message
		//remember to free
		exit(1);
	}
	i = 0;
	while (i < image_count)
	{
		texture = mlx_load_png(textures_world[i]);
		game->world->image[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->world->image[i], TILE_SIZE * 1, TILE_SIZE * 1);
		mlx_delete_texture(texture);
		i++;
	}
	ft_printf("world images got\n");
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
				mlx_image_to_window(game->mlx, game->world->image[5], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->world->image[6], x * TILE_SIZE, y * TILE_SIZE);
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
	mlx_resize_image(game->world->image[0], TILE_SIZE * game->width, TILE_SIZE * game->height);
	//game->image_content = 1;
	get_images_chicken(game, textures_chicken());
	get_images_fox(game, textures_fox());
	get_images_dog(game, textures_dog());
	get_images_fox_reverse(game, textures_fox_reverse());
	get_images_dog_reverse(game, textures_dog_reverse());
	mlx_image_to_window(game->mlx, game->world->image[0], 0, 0);
	insert_images_to_map(game, x, y, i);
	//set_depths(game);
}
