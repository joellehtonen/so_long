/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/31 15:45:00 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->player = malloc(sizeof(t_player));
	if (game->player == NULL)
		display_error(game, "Malloc failed");
	ft_memset(game->player, 0, sizeof(t_player));
	game->enemy = malloc(sizeof(t_enemy));
	if (game->enemy == NULL)
		display_error(game, "Malloc failed");
	ft_memset(game->enemy, 0, sizeof(t_enemy));
	game->chicken = malloc(sizeof(t_chicken));
	if (game->chicken == NULL)
		display_error(game, "Malloc failed");
	ft_memset(game->chicken, 0, sizeof(t_chicken));
}

int	main(int argc, char **argv)
{
	t_game		game;
	mlx_image_t	*image;

	if (argc != 2)
		return (0);
	check_map_format(&game, argv[1]);
	initialize_game(&game);
	get_map_size(&game, argv);
	map_reader(&game, argv);
	check_map_size(&game);
	map_checker(&game);
	game.mlx = mlx_init(game.width * TILE_SIZE,
			game.height * TILE_SIZE, "FOX", true);
	if ((!game.mlx))
		free_and_exit(&game, 1);
	image = mlx_new_image(game.mlx, game.width * TILE_SIZE,
			(game.height + 1) * TILE_SIZE);
	add_graphics(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_image_to_window(game.mlx, image, 0, 0);
	mlx_loop_hook(game.mlx, &controls, &game);
	mlx_loop(game.mlx);
	free_and_exit(&game, 0);
	return (1);
}
