/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/23 11:06:45 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_images_animation_chicken(t_game *game, const char *textures_chicken)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = sizeof(textures_chicken) / sizeof(const char *);
	game->chicken = malloc(sizeof(t_chicken) * animation_count);
	if (game->chicken == NULL)
	{
		perror("FAILED TO ALLOCATE MEMORY FOR CHICKEN ANIMATION\n");
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_chicken[i]);
		game->chicken->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
}

void get_images_animation_fox(t_game *game, const char *textures_fox)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = sizeof(textures_fox) / sizeof(const char *);
	game->player = malloc(sizeof(t_player) * animation_count);
	if (game->player == NULL)
	{
		perror("FAILED TO ALLOCATE MEMORY FOR PLAYER ANIMATION\n");
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_fox[i]);
		game->player->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
}

void get_images_animation_dog(t_game *game, const char *textures_dog)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = sizeof(textures_dog) / sizeof(const char *);
	game->enemy = malloc(sizeof(t_enemy) * animation_count);
	if (game->enemy == NULL)
	{
		perror("FAILED TO ALLOCATE MEMORY FOR ENEMY ANIMATION\n");
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_dog[i]);
		game->enemy->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
}

int idle_animation(t_game *game)
{
	if (game->frame == 0)
	{
		game->player->animation++;
	}
	else
	{
		game->player->animation--;
	}
}
