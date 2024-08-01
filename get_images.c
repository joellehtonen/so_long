/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 11:21:52 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images_chicken(t_game *game)
{
	mlx_texture_t	*texture;

	game->chicken->animation = malloc(sizeof(mlx_image_t *));
	if (game->chicken->animation == NULL)
		display_error(game, "Malloc for images failed");
	texture = mlx_load_png("textures/chicken_sit1.png");
	game->chicken->animation[0] = mlx_texture_to_image(game->mlx, texture);
	if (!game->chicken->animation[0])
		display_error(game, "Failed to load image");
	mlx_resize_image(game->chicken->animation[0],
		TILE_SIZE * 1.5, TILE_SIZE);
	mlx_delete_texture(texture);
}

void	get_images_fox(t_game *game)
{
	mlx_texture_t	*texture;

	game->player->animation = malloc(sizeof(mlx_image_t *));
	if (game->player->animation == NULL)
		display_error(game, "Malloc for images failed");
	texture = mlx_load_png("textures/fox_run1.png");
	game->player->animation[0] = mlx_texture_to_image(game->mlx, texture);
	if (!game->player->animation[0])
		display_error(game, "Failed to load image");
	mlx_resize_image(game->player->animation[0],
		TILE_SIZE * 1.5, TILE_SIZE);
	mlx_delete_texture(texture);
}

