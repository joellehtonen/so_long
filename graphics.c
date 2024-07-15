/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/15 16:55:14 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->txts = ft_calloc(1, sizeof(t_textures));
	game->txts->wall = mlx_load_png("textures/wall.png");
	game->txts->exit = mlx_load_png("textures/exit.png");
	game->txts->player = mlx_load_png("textures/player.png");
	game->txts->collect = mlx_load_png("textures/collect.png");
}

void	get_images(t_game *game)
{
	get_textures(game);
	game->imgs = ft_calloc(1, sizeof(t_images));
	game->imgs->wall = mlx_texture_to_image(game->mlx, game->txts->wall);
	game->imgs->exit = mlx_texture_to_image(game->mlx, game->txts->exit);
	game->imgs->player = mlx_texture_to_image(game->mlx, game->txts->player);
	game->imgs->collect = mlx_texture_to_image(game->mlx, game->txts->collect);
	mlx_resize_image(game->imgs->wall, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->exit, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->player, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->imgs->collect, TILE_SIZE, TILE_SIZE);
	mlx_delete_texture(game->txts->wall);
	mlx_delete_texture(game->txts->exit);
	mlx_delete_texture(game->txts->player);
	mlx_delete_texture(game->txts->collect);
}

void	add_graphics(t_game *game)
{
	int x;
	int y;

	get_images(game);
	y = 0;
	ft_printf("GRAPHICS: \n");
	int i = 0;
	while (i < game->height)
	{
	 	ft_printf("%s", game->map[i]);
	  	i++;
	}
	ft_printf("\n");
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			// if (game->map[y][x] == '0')
			// 	mlx_image_to_window(game->mlx, game->imgs->ground, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->imgs->wall, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'e')
				mlx_image_to_window(game->mlx, game->imgs->exit, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'c')
				mlx_image_to_window(game->mlx, game->imgs->collect, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'p')
				mlx_image_to_window(game->mlx, game->imgs->player, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
