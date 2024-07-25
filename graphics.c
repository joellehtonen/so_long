/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 10:22:28 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	set_depths(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	while ()
// 		mlx_set_instance_depth(&game->world->image[1]->instances[0], 1);
// }

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
		mlx_resize_image(game->world->image[i], TILE_SIZE * 0.9, TILE_SIZE * 0.9);
		mlx_delete_texture(texture);
		i++;
	}
	ft_printf("world textures got\n");
}

void	insert_images_to_map(t_game *game, int x, int y)
{
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
			{
				wall_randomizer(game, x, y);
				//mlx_image_to_window(game->mlx, game->world->image[1], x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (game->map[y][x] == 'e')
			{
				mlx_image_to_window(game->mlx, game->world->image[5], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->world->image[6], x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (game->map[y][x] == 'c')
			{
				upload_chicken_animations(game, x, y);
				//mlx_image_to_window(game->mlx, game->chicken->animation[3], x * TILE_SIZE, y * TILE_SIZE);
				//mlx_image_to_window(game->mlx, game->chicken->animation[0], x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (game->map[y][x] == 'p')
			{
				upload_player_and_enemy_animations(game, x, y);
				update_locations(game, x, y);
			}
			x++;
			//ft_printf("x is %d\n", x);
		}
		y++;
		//ft_printf("y is %d\n", y);
	}
}

void	add_graphics(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	get_images_world(game, textures_world());
	mlx_resize_image(game->world->image[0], TILE_SIZE * game->width, TILE_SIZE * game->height);
	//game->image_content = 1;
	get_images_chicken(game, textures_chicken());
	get_images_fox(game, textures_fox());
	get_images_dog(game, textures_dog());
	mlx_image_to_window(game->mlx, game->world->image[0], 0, 0);
	insert_images_to_map(game, x, y);
	//set_depths(game);
}

// void	get_textures(t_game *game)
// {
// 	game->txts = ft_calloc(1, sizeof(t_textures));
// 	game->txts->wall = mlx_load_png("textures/wall_1.png");
// 	game->txts->exit = mlx_load_png("textures/exit_yellow.png");
// 	game->txts->exit_ready = mlx_load_png("textures/exit_green-ish.png");
// 	game->txts->player = mlx_load_png("textures/fox.png");
// 	game->txts->collect = mlx_load_png("textures/chicken.png");
// 	game->txts->ground = mlx_load_png("textures/green.png");
// 	game->txts->enemy = mlx_load_png("textures/enemy.png");
// 	ft_printf("textures got\n");
// }

// void	get_images(t_game *game)
// {
// 	get_textures(game);
// 	game->imgs = ft_calloc(1, sizeof(t_images));
// 	game->imgs->wall = mlx_texture_to_image(game->mlx, game->txts->wall);
// 	game->imgs->exit = mlx_texture_to_image(game->mlx, game->txts->exit);
// 	game->imgs->exit_ready = mlx_texture_to_image(game->mlx, game->txts->exit_ready);
// 	game->imgs->player = mlx_texture_to_image(game->mlx, game->txts->player);
// 	game->imgs->collect = mlx_texture_to_image(game->mlx, game->txts->collect);
// 	game->imgs->ground = mlx_texture_to_image(game->mlx, game->txts->ground);
// 	game->imgs->enemy = mlx_texture_to_image(game->mlx, game->txts->enemy);
// 	mlx_resize_image(game->imgs->wall, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->exit, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->exit_ready, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->player, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->collect, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->enemy, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->ground, TILE_SIZE * game->width, TILE_SIZE * game->height);
// 	//mlx_resize_image(game->imgs->ground, TILE_SIZE, TILE_SIZE);
// 	mlx_delete_texture(game->txts->wall);
// 	mlx_delete_texture(game->txts->exit);
// 	mlx_delete_texture(game->txts->exit_ready);
// 	mlx_delete_texture(game->txts->player);
// 	mlx_delete_texture(game->txts->collect);
// 	mlx_delete_texture(game->txts->ground);
// 	mlx_delete_texture(game->txts->enemy);
// 	ft_printf("images got\n");
// }
