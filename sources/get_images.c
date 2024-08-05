/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/05 12:47:53 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images_chicken(t_game *game)
{
	game->chicken->animation = malloc(2 * sizeof(mlx_image_t *));
	if (game->chicken->animation == NULL)
		display_error(game, "Malloc failed");
	game->texture = mlx_load_png("textures/chicken_sit.png");
	if (game->texture == NULL)
		display_error(game, "Failed to load texture");
	game->chicken->animation[0]
		= mlx_texture_to_image(game->mlx, game->texture);
	if (!game->chicken->animation[0])
		display_error(game, "Failed to load image");
	mlx_resize_image(game->chicken->animation[0],
		TILE_SIZE * 1.5, TILE_SIZE);
	mlx_delete_texture(game->texture);
	game->chicken->animation[1] = NULL;
}

void	get_images_fox(t_game *game)
{
	game->player->animation = malloc(2 * sizeof(mlx_image_t *));
	if (game->player->animation == NULL)
		display_error(game, "Malloc failed");
	game->texture = mlx_load_png("textures/fox_idle1.png");
	if (game->texture == NULL)
		display_error(game, "Failed to load texture");
	game->player->animation[0]
		= mlx_texture_to_image(game->mlx, game->texture);
	if (!game->player->animation[0])
		display_error(game, "Failed to load image");
	mlx_resize_image(game->player->animation[0],
		TILE_SIZE * 1.5, TILE_SIZE);
	mlx_delete_texture(game->texture);
	game->player->animation[1] = NULL;
}
