/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/08 13:56:42 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_textures(t_game *game)
{
	game->txts = ft_calloc(1, sizeof(t_textures));
	game->txts->ground = mlx_load_png("textures/ground.png");
	game->txts->wall = mlx_load_png("textures/wall.png");
	game->txts->exit = mlx_load_png("textures/exit.png");
	game->txts->player = mlx_load_png("textures/player.png");
	game->txts->collect = mlx_load_png("textures/collect.png");
}

void	get_images(t_game *game)
{
	get_textures(&game);
	game->imgs = ft_calloc(1, sizeof(t_images));
	game->imgs->ground = mlx_texture_to_image(game->mlx, game->txts->ground);
	game->imgs->wall = mlx_texture_to_image(game->mlx, game->txts->wall);
	game->imgs->exit = mlx_texture_to_image(game->mlx, game->txts->exit);
	game->imgs->player = mlx_texture_to_image(game->mlx, game->txts->player);
	game->imgs->collect = mlx_texture_to_image(game->mlx, game->txts->collect);
	mlx_delete_texture(game->txts->ground);
	mlx_delete_texture(game->txts->wall);
	mlx_delete_texture(game->txts->exit);
	mlx_delete_texture(game->txts->player);
	mlx_delete_texture(game->txts->collect);
}

void	add_graphics(t_game *game)
{
	int x;
	int y;

	get_images(&game);
	y = 0;
	while (y <= game->height)
	{
		x = 0;
		while (x <= game->width)
		{
			if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->imgs->ground, x, y);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->imgs->wall, x, y);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->imgs->exit, x, y);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->imgs->collect, x, y);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->imgs->player, x, y);
			x++;
		}
		y++;
	}
}
