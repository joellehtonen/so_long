/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/26 12:21:28 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_variables(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->collectables = 0;
	game->collected = 0;
	game->exit = 0;
	game->start = 0;
	game->move_count = 0;
	game->map = NULL;
	// game->world->image = NULL;
	// game->player->animation = NULL;
	// game->enemy->animation = NULL;
	// game->chicken->animation = NULL;
	// game->player->reverse_animation = NULL;
	// game->enemy->reverse_animation = NULL;
	game->image_content = 0;
	game->enemy->active = 0;
	game->frame = 0;
	game->player->frame = 0;
	game->enemy->frame = 0;
	game->enemy->dying = 0;
	game->enemy->animation_timer = 0;
	game->enemy->move_count = 0;
	game->player->animation_timer = 0;
	game->chicken->animation_timer = 0;
	game->player->dying = 0;
	game->chicken->dying = 0;
	game->player->left = 0;
	game->enemy->left = 0;
	game->world->image_count = 0;
}

void	initialize_game(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (game->player == NULL)
		free_and_exit(game, 1);
	game->enemy = malloc(sizeof(t_enemy));
	if (game->enemy == NULL)
		free_and_exit(game, 1);
	game->chicken = malloc(sizeof(t_chicken));
	if (game->chicken == NULL)
		free_and_exit(game, 1);
	game->world = malloc(sizeof(t_world)); 
	if (game->world == NULL)
		free_and_exit(game, 1);
	initialize_variables(game);
	// ft_memset(game, 0, sizeof(game));
	// ft_memset(game->player, 0, sizeof(game->player));
	// ft_memset(game->enemy, 0, sizeof(game->enemy));
	// ft_memset(game->chicken, 0, sizeof(game->chicken));
	// ft_memset(game->world, 0, sizeof(game->world));
}

int main(int argc, char **argv)
{
	t_game 		game;
	mlx_image_t *image;

	if (argc > 3)
		return (0);
	initialize_game(&game);
	//ft_printf("variables ready\n");
	map_reader(&game, argv);
	//ft_printf("map read\n");
	map_checker(&game);
	//ft_printf("map checked\n");
	game.mlx = mlx_init(game.width * TILE_SIZE, game.height * TILE_SIZE, "FOX", true);
	//ft_printf("mlx\n");
	// if ((!game.mlx))
	// 	free_and_exit(&game, 1);
	image = mlx_new_image(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE);
	//ft_printf("new image\n");
	add_graphics(&game);
	//ft_printf("graphics added\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	//mlx_set_setting(MLX_MAXIMIZED, 1);
	//mlx_set_setting(MLX_DECORATED, 0);
	mlx_image_to_window(game.mlx, image, 0, 0);
	mlx_loop_hook(game.mlx, &controls, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_and_exit(&game, 0);
	return (1);
}
