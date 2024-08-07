/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:23:10 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 09:32:34 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

const char	**textures_dog(void)
{
	static const char	*textures_dog[13];

	textures_dog[0] = "textures/dog_run1.png";
	textures_dog[1] = "textures/dog_run2.png";
	textures_dog[2] = "textures/dog_run3.png";
	textures_dog[3] = "textures/dog_run4.png";
	textures_dog[4] = "textures/dog_run5.png";
	textures_dog[5] = "textures/dog_run6.png";
	textures_dog[6] = "textures/dog_run7.png";
	textures_dog[7] = "textures/dog_run8.png";
	textures_dog[8] = "textures/dog_die1.png";
	textures_dog[9] = "textures/dog_die2.png";
	textures_dog[10] = "textures/dog_die3.png";
	textures_dog[11] = "textures/dog_die4.png";
	textures_dog[12] = NULL;
	return (textures_dog);
}

const char	**textures_dog_reverse(void)
{
	static const char	*textures_dog_reverse[13];

	textures_dog_reverse[0] = "textures/dog_run1_r.png";
	textures_dog_reverse[1] = "textures/dog_run2_r.png";
	textures_dog_reverse[2] = "textures/dog_run3_r.png";
	textures_dog_reverse[3] = "textures/dog_run4_r.png";
	textures_dog_reverse[4] = "textures/dog_run5_r.png";
	textures_dog_reverse[5] = "textures/dog_run6_r.png";
	textures_dog_reverse[6] = "textures/dog_run7_r.png";
	textures_dog_reverse[7] = "textures/dog_run8_r.png";
	textures_dog_reverse[8] = "textures/dog_die1_r.png";
	textures_dog_reverse[9] = "textures/dog_die2_r.png";
	textures_dog_reverse[10] = "textures/dog_die3_r.png";
	textures_dog_reverse[11] = "textures/dog_die4_r.png";
	textures_dog_reverse[12] = NULL;
	return (textures_dog_reverse);
}

void	get_images_dog(t_game *game, const char **textures_dog)
{
	int				count;
	int				i;

	count = 0;
	while (textures_dog[count])
		count++;
	game->enemy->anim = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->enemy->anim == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->text = mlx_load_png(textures_dog[i]);
		if (game->text == NULL)
			display_error(game, "Failed to load texture");
		game->enemy->anim[i] = mlx_texture_to_image(game->mlx, game->text);
		if (!game->enemy->anim[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->enemy->anim[i],
			TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->text);
		i++;
	}
	game->text = NULL;
	game->enemy->anim[i] = NULL;
}

void	get_images_dog_reverse(t_game *game, const char **textures_dog_reverse)
{
	int				count;
	int				i;

	count = 0;
	while (textures_dog_reverse[count])
		count++;
	game->enemy->rev_anim = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->enemy->rev_anim == NULL)
		display_error(game, "Malloc failed");
	i = 0;
	while (i < count)
	{
		game->text = mlx_load_png(textures_dog_reverse[i]);
		if (game->text == NULL)
			display_error(game, "Failed to load texture");
		game->enemy->rev_anim[i]
			= mlx_texture_to_image(game->mlx, game->text);
		if (!game->enemy->rev_anim[i])
			display_error(game, "Failed to load image");
		mlx_resize_image(game->enemy->rev_anim[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(game->text);
		i++;
	}
	game->text = NULL;
	game->enemy->rev_anim[i] = NULL;
}

void	upload_enemy_animations(t_game *game, int x, int y)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->enemy->anim[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->anim[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->anim[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->rev_anim[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->rev_anim[i]->instances[0].enabled = false;
		i++;
	}
	game->enemy->x = game->player->x;
	game->enemy->y = game->player->y;
}
