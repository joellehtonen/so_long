/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 15:25:53 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_images_chicken(t_game *game, const char **textures_chicken)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while (textures_chicken[animation_count])
		animation_count++;
	game->chicken->animation = malloc(sizeof(mlx_image_t *) * (animation_count + 1));
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
	while (textures_fox[animation_count])
		animation_count++;
	game->player->animation = malloc(sizeof(mlx_image_t *) * (animation_count + 1));
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

void get_images_fox_reverse(t_game *game, const char **textures_fox_reverse)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while (textures_fox_reverse[animation_count])
		animation_count++;
	game->player->reverse_animation = malloc(sizeof(mlx_image_t *) * (animation_count + 1));
	if (game->player->reverse_animation == NULL)
	{
		//error message
		//remember to free
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_fox_reverse[i]);
		game->player->reverse_animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->player->reverse_animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	game->player->reverse_animation[i] = NULL;
	ft_printf("reverse fox images got\n");
}

void get_images_dog(t_game *game, const char **textures_dog)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while (textures_dog[animation_count])
		animation_count++;
	game->enemy->animation = malloc(sizeof(mlx_image_t *) * (animation_count + 1));
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

void get_images_dog_reverse(t_game *game, const char **textures_dog_reverse)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = 0;
	while (textures_dog_reverse[animation_count])
		animation_count++;
	game->enemy->reverse_animation = malloc(sizeof(mlx_image_t *) * (animation_count + 1));
	if (game->enemy->reverse_animation == NULL)
	{
		//error message
		//remember to free
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_dog_reverse[i]);
		game->enemy->reverse_animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->enemy->reverse_animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	game->enemy->reverse_animation[i] = NULL;
	ft_printf("reverse dog images got\n");
}
