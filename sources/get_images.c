/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 10:33:34 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images_chicken(t_game *game)
{
	game->chicken->animation = malloc(2 * sizeof(mlx_image_t *));
	if (game->chicken->animation == NULL)
		display_error(game, "Malloc failed");
	game->text = mlx_load_png("textures/chicken_sit.png");
	if (game->text == NULL)
		display_error(game, "Failed to load texture");
	game->chicken->animation[0] = mlx_texture_to_image(game->mlx, game->text);
	if (!game->chicken->animation[0])
		display_error(game, "Failed to load image");
	mlx_resize_image(game->chicken->animation[0],
		TILE_SIZE * 1.5, TILE_SIZE);
	mlx_delete_texture(game->text);
	game->text = NULL;
	game->chicken->animation[1] = NULL;
}

void	get_images_fox(t_game *game)
{
	game->player->animation = malloc(2 * sizeof(mlx_image_t *));
	if (game->player->animation == NULL)
		display_error(game, "Malloc failed");
	game->text = mlx_load_png("textures/fox_idle1.png");
	if (game->text == NULL)
		display_error(game, "Failed to load texture");
	game->player->animation[0] = mlx_texture_to_image(game->mlx, game->text);
	if (!game->player->animation[0])
		display_error(game, "Failed to load image");
	mlx_resize_image(game->player->animation[0],
		TILE_SIZE * 1.5, TILE_SIZE);
	mlx_delete_texture(game->text);
	game->text = NULL;
	game->player->animation[1] = NULL;
}
