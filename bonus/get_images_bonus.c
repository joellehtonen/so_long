/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/05 12:50:59 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_images_chicken(t_game *game, const char **textures_chicken)
{
	int				count;
	int				i;

	count = 0;
	while (textures_chicken[count])
		count++;
	game->chicken->animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->chicken->animation == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->texture = mlx_load_png(textures_chicken[i]);
		if (game->texture == NULL)
			display_error(game, "Failed to load texture");
		game->chicken->animation[i]
			= mlx_texture_to_image(game->mlx, game->texture);
		if (!game->chicken->animation[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->chicken->animation[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->texture);
		i++;
	}
	game->chicken->animation[i] = NULL;
}

void	get_images_fox(t_game *game, const char **textures_fox)
{
	int				count;
	int				i;

	count = 0;
	while (textures_fox[count])
		count++;
	game->player->animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->player->animation == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->texture = mlx_load_png(textures_fox[i]);
		if (game->texture == NULL)
			display_error(game, "Failed to load texture");
		game->player->animation[i]
			= mlx_texture_to_image(game->mlx, game->texture);
		if (!game->player->animation[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->player->animation[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->texture);
		i++;
	}
	game->player->animation[i] = NULL;
}

void	get_images_fox_reverse(t_game *game, const char **textures_fox_reverse)
{
	int				count;
	int				i;

	count = 0;
	while (textures_fox_reverse[count])
		count++;
	game->player->rev_anim = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->player->rev_anim == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->texture = mlx_load_png(textures_fox_reverse[i]);
		if (game->texture == NULL)
			display_error(game, "Failed to load texture");
		game->player->rev_anim[i]
			= mlx_texture_to_image(game->mlx, game->texture);
		if (!game->player->rev_anim[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->player->rev_anim[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->texture);
		i++;
	}
	game->player->rev_anim[i] = NULL;
}
