/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:28:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 09:43:42 by jlehtone         ###   ########.fr       */
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
	game->chicken->anim = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->chicken->anim == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->txt = mlx_load_png(textures_chicken[i]);
		if (game->txt == NULL)
			display_error(game, "Failed to load texture");
		game->chicken->anim[i] = mlx_texture_to_image(game->mlx, game->txt);
		if (!game->chicken->anim[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->chicken->anim[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->txt);
		i++;
	}
	game->txt = NULL;
	game->chicken->anim[i] = NULL;
}

void	get_images_fox(t_game *game, const char **textures_fox)
{
	int				count;
	int				i;

	count = 0;
	while (textures_fox[count])
		count++;
	game->player->anim = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->player->anim == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->txt = mlx_load_png(textures_fox[i]);
		if (game->txt == NULL)
			display_error(game, "Failed to load texture");
		game->player->anim[i] = mlx_texture_to_image(game->mlx, game->text);
		if (!game->player->anim[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->player->anim[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->txt);
		i++;
	}
	game->txt = NULL;
	game->player->anim[i] = NULL;
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
		game->txt = mlx_load_png(textures_fox_reverse[i]);
		if (game->txt == NULL)
			display_error(game, "Failed to load texture");
		game->player->rev_anim[i] = mlx_texture_to_image(game->mlx, game->txt);
		if (!game->player->rev_anim[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->player->rev_anim[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->txt);
		i++;
	}
	game->txt = NULL;
	game->player->rev_anim[i] = NULL;
}
