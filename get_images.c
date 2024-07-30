/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 15:24:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images_chicken(t_game *game, const char **textures_chicken)
{
	mlx_texture_t	*texture;
	int				count;
	int				i;

	count = 0;
	while (textures_chicken[count])
		count++;
	game->chicken->animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->chicken->animation == NULL)
	{
		display_error(game, "Malloc for images failed");
	}
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_chicken[i]);
		game->chicken->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->chicken->animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	 game->chicken->animation[i] = NULL;
	//ft_printf("chicken images got\n");
}

void get_images_fox(t_game *game, const char **textures_fox)
{
	mlx_texture_t	*texture;
	int				count;
	int				i;

	count = 0;
	while (textures_fox[count])
		count++;
	game->player->animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->player->animation == NULL)
	{
		display_error(game, "Malloc for images failed");
	}
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_fox[i]);
		game->player->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->player->animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	game->player->animation[i] = NULL;
	//ft_printf("fox images got\n");
}

void get_images_fox_reverse(t_game *game, const char **textures_fox_reverse)
{
	mlx_texture_t	*texture;
	int				count;
	int				i;i;

	count = 0;
	while (textures_fox_reverse[count])
		count++;
	game->player->reverse_animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->player->reverse_animation == NULL)
	{
		display_error(game, "Malloc for images failed");
	}
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_fox_reverse[i]);
		game->player->reverse_animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->player->reverse_animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	game->player->reverse_animation[i] = NULL;
	//ft_printf("reverse fox images got\n");
}

void get_images_dog(t_game *game, const char **textures_dog)
{
	mlx_texture_t	*texture;
	int				count;
	int				i;;

	count = 0;
	while (textures_dog[count])
		count++;
	game->enemy->animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->enemy->animation == NULL)
	{
		display_error(game, "Malloc for images failed");
	}
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_dog[i]);
		game->enemy->animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->enemy->animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	game->enemy->animation[i] = NULL;
	//ft_printf("dog images got\n");
}

void get_images_dog_reverse(t_game *game, const char **textures_dog_reverse)
{
	mlx_texture_t	*texture;
	int				count;
	int				i;

	count = 0;
	while (textures_dog_reverse[count])
		count++;
	game->enemy->reverse_animation = malloc(sizeof(mlx_image_t *) * (count + 1));
	if (game->enemy->reverse_animation == NULL)
	{
		display_error(game, "Malloc for images failed");
	}
	i = 0;
	while (i < count)
	{
		texture = mlx_load_png(textures_dog_reverse[i]);
		game->enemy->reverse_animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_resize_image(game->enemy->reverse_animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		mlx_delete_texture(texture);
		i++;
	}
	game->enemy->reverse_animation[i] = NULL;
	//ft_printf("reverse dog images got\n");
}