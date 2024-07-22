/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:35:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/22 15:15:10 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void resize_images(t_game *game)
{
	int i;
	int world_count;
	int animation_count;
	
	world_count = sizeof(game->world) / sizeof(const char *);
	animation_count = sizeof(game->animation) / sizeof(const char *);
	mlx_resize_image(game->world->images_world[0], TILE_SIZE * game->width, TILE_SIZE * game->height);
	i = 1;
	while (i < world_count)
	{
		mlx_resize_image(game->world->images_world[i], TILE_SIZE, TILE_SIZE);
		i++;
	}
	i = 0;
	while (i < animation_count)
	{
		if (i < 4)
			mlx_resize_image(game->animation->images_animation[i], TILE_SIZE, TILE_SIZE);
		else
			mlx_resize_image(game->animation->images_animation[i], TILE_SIZE * 1.5, TILE_SIZE);
		i++;
	}
}

void get_images_animation(t_game *game, const char *textures_animation)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = sizeof(textures_animation) / sizeof(const char *);
	game->animation = malloc(sizeof(t_images_animation) * animation_count);
	if (game->animation == NULL)
	{
		perror("FAILED TO ALLOCATE MEMORY FOR ANIMATION IMAGES\n");
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_animation[i]);
		game->animation->images_animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
}

void get_images_world(t_game *game, const char **textures_world)
{
	int	i;
	int world_count;
	mlx_texture_t *texture;

	world_count = sizeof(textures_world) / sizeof(const char *);
	game->world = malloc(sizeof(t_images_world) * world_count);
	if (game->world == NULL)
	{
		perror("FAILED TO ALLOCATE MEMORY FOR WORLD IMAGES\n");
		exit(1);
	}
	i = 0;
	while (i < world_count)
	{
		texture = mlx_load_png(textures_world[i]);
		game->world->images_world[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
}

void	insert_images_to_map(t_game *game, int x, int y)
{
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				wall_randomizer(game, x, y);
			else if (game->map[y][x] == 'e')
			{
				mlx_image_to_window(game->mlx, game->world->images_world[5], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->world->images_world[6], x * TILE_SIZE, y * TILE_SIZE);
			}
			else if (game->map[y][x] == 'c')
				mlx_image_to_window(game->mlx, game->animation->images_animation[0], x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'p')
			{
				mlx_image_to_window(game->mlx, game->animation->images_animation[4], x * TILE_SIZE, y * TILE_SIZE);
				mlx_image_to_window(game->mlx, game->animation->images_animation[12], x * TILE_SIZE, y * TILE_SIZE);
				ready_enemy(game, x, y);
			}
			x++;
		}
		y++;
	}
}

void	add_graphics(t_game *game)
{
	int x;
	int y;
	
	get_images_world(game, texture_names_world());
	get_images_animation_chicken(game, texture_names_animation());
	get_images_animation_fox(game, texture_names_animation());
	get_images_animation_dog(game, texture_names_animation());
	resize_images(game);
	mlx_image_to_window(game->mlx, game->world->images_world[0], 0, 0);
	insert_images_to_map(game, x, y);
}

// void	get_textures(t_game *game)
// {
// 	game->txts = ft_calloc(1, sizeof(t_textures));
// 	game->txts->wall = mlx_load_png("textures/wall_1.png");
// 	game->txts->exit = mlx_load_png("textures/exit_yellow.png");
// 	game->txts->exit_ready = mlx_load_png("textures/exit_green-ish.png");
// 	game->txts->player = mlx_load_png("textures/fox.png");
// 	game->txts->collect = mlx_load_png("textures/chicken.png");
// 	game->txts->ground = mlx_load_png("textures/green.png");
// 	game->txts->enemy = mlx_load_png("textures/enemy.png");
// 	ft_printf("textures got\n");
// }

// void	get_images(t_game *game)
// {
// 	get_textures(game);
// 	game->imgs = ft_calloc(1, sizeof(t_images));
// 	game->imgs->wall = mlx_texture_to_image(game->mlx, game->txts->wall);
// 	game->imgs->exit = mlx_texture_to_image(game->mlx, game->txts->exit);
// 	game->imgs->exit_ready = mlx_texture_to_image(game->mlx, game->txts->exit_ready);
// 	game->imgs->player = mlx_texture_to_image(game->mlx, game->txts->player);
// 	game->imgs->collect = mlx_texture_to_image(game->mlx, game->txts->collect);
// 	game->imgs->ground = mlx_texture_to_image(game->mlx, game->txts->ground);
// 	game->imgs->enemy = mlx_texture_to_image(game->mlx, game->txts->enemy);
// 	mlx_resize_image(game->imgs->wall, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->exit, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->exit_ready, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->player, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->collect, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->enemy, TILE_SIZE, TILE_SIZE);
// 	mlx_resize_image(game->imgs->ground, TILE_SIZE * game->width, TILE_SIZE * game->height);
// 	//mlx_resize_image(game->imgs->ground, TILE_SIZE, TILE_SIZE);
// 	mlx_delete_texture(game->txts->wall);
// 	mlx_delete_texture(game->txts->exit);
// 	mlx_delete_texture(game->txts->exit_ready);
// 	mlx_delete_texture(game->txts->player);
// 	mlx_delete_texture(game->txts->collect);
// 	mlx_delete_texture(game->txts->ground);
// 	mlx_delete_texture(game->txts->enemy);
// 	ft_printf("images got\n");
// }
