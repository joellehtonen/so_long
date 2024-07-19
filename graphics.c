/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/19 13:46:04 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->txts = ft_calloc(1, sizeof(t_textures));
	game->txts->wall = mlx_load_png("textures/wall.png");
	game->txts->exit = mlx_load_png("textures/exit_yellow.png");
	game->txts->exit_ready = mlx_load_png("textures/exit_kinda_green.png");
	game->txts->player = mlx_load_png("textures/fox.png");
	game->txts->collect = mlx_load_png("textures/chicken.png");
	game->txts->ground = mlx_load_png("textures/green.png");
	game->txts->enemy = mlx_load_png("textures/enemy.png");
}

void	get_images(t_game *game)
{
	get_textures(game);
	game->imgs = ft_calloc(1, sizeof(t_images));
	game->imgs->wall = mlx_texture_to_image(game->mlx, game->txts->wall);
	game->imgs->exit = mlx_texture_to_image(game->mlx, game->txts->exit);
	game->imgs->exit_ready = mlx_texture_to_image(game->mlx, game->txts->exit_ready);
	game->imgs->player = mlx_texture_to_image(game->mlx, game->txts->player);
	game->imgs->collect = mlx_texture_to_image(game->mlx, game->txts->collect);
	game->imgs->ground = mlx_texture_to_image(game->mlx, game->txts->ground);
	game->imgs->enemy = mlx_texture_to_image(game->mlx, game->txts->enemy);
	mlx_resize_image(game->imgs->wall, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->exit, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->exit_ready, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->player, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->collect, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->enemy, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->ground, TILE_SIZE * game->width, TILE_SIZE * game->height);
	//mlx_resize_image(game->imgs->ground, TILE_SIZE, TILE_SIZE);
	mlx_delete_texture(game->txts->wall);
	mlx_delete_texture(game->txts->exit);
	mlx_delete_texture(game->txts->exit_ready);
	mlx_delete_texture(game->txts->player);
	mlx_delete_texture(game->txts->collect);
	mlx_delete_texture(game->txts->ground);
	mlx_delete_texture(game->txts->enemy);
}

void	add_graphics(t_game *game)
{
	int x;
	int y;

	get_images(game);
	mlx_image_to_window(game->mlx, game->imgs->ground, 0, 0);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			//mlx_image_to_window(game->mlx, game->imgs->ground, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->imgs->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'e')
			{
				mlx_image_to_window(game->mlx, game->imgs->exit_ready, x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->imgs->exit, x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (game->map[y][x] == 'c')
				mlx_image_to_window(game->mlx, game->imgs->collect, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'p')
			{
				mlx_image_to_window(game->mlx, game->imgs->player, x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->imgs->enemy, x * TILE_SIZE, y * TILE_SIZE);
				game->player->x = game->imgs->player->instances[0].x;
				game->player->y = game->imgs->player->instances[0].y;
				game->enemy->x = game->imgs->player->instances[0].x;
				game->enemy->y = game->imgs->player->instances[0].y;
				game->imgs->enemy->instances[0].enabled = false;
			}
			x++;
		}
		y++;
	}
}
