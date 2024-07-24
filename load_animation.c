/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/24 16:03:58 by jlehtone         ###   ########.fr       */
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
	game->chicken->animation = malloc(sizeof(mlx_image_t *) * animation_count + 1);
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
		mlx_resize_image(game->chicken->animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	 game->chicken->animation[i] = NULL;
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
	game->player->animation = malloc(sizeof(mlx_image_t *) * animation_count + 1);
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
	game->player->animation[i] = NULL;
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
	game->enemy->animation = malloc(sizeof(mlx_image_t *) * animation_count + 1);
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
	game->enemy->animation[i] = NULL;
	ft_printf("dog images got\n");
}

void	upload_player_and_enemy_animations(t_game *game, int x, int y)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	while(game->player->animation[count] != NULL)
		count++;
	//ft_printf("player count is %d\n", count);
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->player->animation[i], x * TILE_SIZE, y * TILE_SIZE);
		game->player->animation[i]->instances[0].enabled = false;
		//ft_printf("Uploaded player animation %d at (%d, %d)\n", i, x * TILE_SIZE, y * TILE_SIZE);
		i++;
	}
	game->player->animation[0]->instances[0].enabled = true;
	i = 0;
	count = 0;
	while(game->enemy->animation[count] != NULL)
		count++;
	//ft_printf("enemy count is %d\n", count);
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->animation[i], x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->animation[i]->instances[0].enabled = false;
		//ft_printf("Uploaded enemy animation %d at (%d, %d)\n", i, x * TILE_SIZE, y * TILE_SIZE);
		i++;
	}
}

void	upload_chicken_animations(t_game *game, int x, int y)
{
	int count;
	int i;
	
	i = 0;
	count = 0;
	while(game->chicken->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->chicken->animation[i], x * TILE_SIZE, y * TILE_SIZE);
		game->chicken->animation[i]->instances[0].enabled = false;
		i++;
	}
	game->chicken->animation[0]->instances[0].enabled = true;
}
