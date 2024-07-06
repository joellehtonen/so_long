/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/06 14:28:21 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(t_game *game)
{
	
	// game->ground = mlx_png_file_to_image(game->mlx, "images/ground.png", 0, 0);
	// game->wall = mlx_png_file_to_image(game->mlx, "images/wall.png", 0, 0);
	// game->player = mlx_png_file_to_image(game->mlx, "images/player.png", 0, 0);
	// game->exit = mlx_png_file_to_image(game->mlx, "images/exit.png", 0, 0);
	// game->collectables = mlx_png_file_to_image(game->mlx, "images/collectables.png", 0, 0);
}

void	add_graphics(t_game *game)
{
	int x;
	int y;

	initialize_images(&game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window();
			if (game->map[y][x] == 'C')
				mlx_image_to_window();
			if (game->map[y][x] == 'P')
				mlx_image_to_window();
			if (game->map[y][x] == 'E')
				mlx_image_to_window();
			if (game->map[y][x] == '0')
				mlx_image_to_window();
			x++;
		}
		y++;
	}
}
