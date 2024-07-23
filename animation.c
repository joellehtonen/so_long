/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/23 15:38:36 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_images_chicken(t_game *game, const char **textures_chicken)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while(textures_chicken[animation_count])
		animation_count++;
	//animation_count = sizeof(textures_dog) / sizeof(const char *);
	game->chicken = malloc(sizeof(t_chicken)); 
	if (game->chicken == NULL)
	{
		//error message
		free(game->chicken);
		exit(1);
	}
	game->chicken->animation = malloc(sizeof(mlx_image_t *) * animation_count);
	if (game->chicken->animation == NULL)
	{
		//error message
		//remember to free
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_chicken[i]);
		game->chicken->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->chicken->animation[i], TILE_SIZE, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	ft_printf("chicken images got\n");
}

void get_images_fox(t_game *game, const char **textures_fox)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while(textures_fox[animation_count])
		animation_count++;
	game->player = malloc(sizeof(t_player)); 
	if (game->player == NULL)
	{
		//error message
		free(game->player);
		exit(1);
	}
	game->player->animation = malloc(sizeof(mlx_image_t *) * animation_count);
	if (game->player->animation == NULL)
	{
		//error message
		//remember to free
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_fox[i]);
		game->player->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->player->animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	ft_printf("fox images got\n");
}

void get_images_dog(t_game *game, const char **textures_dog)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while(textures_dog[animation_count])
		animation_count++;
	game->enemy = malloc(sizeof(t_enemy)); 
	if (game->enemy == NULL)
	{
		//error message
		free(game->enemy);
		exit(1);
	}
	game->enemy->animation = malloc(sizeof(mlx_image_t *) * animation_count);
	if (game->enemy->animation == NULL)
	{
		//error message
		//remember to free
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_dog[i]);
		game->enemy->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->enemy->animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	ft_printf("dog images got\n");
}

// void idle_animation(t_game *game)
// {
// 	if (game->player->frame == 0)
// 	{
// 		game->player->animation = 1;
// 		game->player->frame = 0;
// 	}
// 	else
// 	{
// 		game->player->animation = 0;
// 		game->player->frame = 1;
// 	}
// }
