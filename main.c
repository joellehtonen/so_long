/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 15:14:37 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_func(void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	free_and_exit(game);
}

static void	validate_map(t_game *game, char**argv)
{
	get_map_size(game, argv);
	map_reader(game, argv);
	check_map_size(game);
	map_checker(game);
}

static void	initialize_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->player = malloc(sizeof(t_player));
	if (game->player == NULL)
		display_error(game, "Malloc failed");
	ft_memset(game->player, 0, sizeof(t_player));
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
	validate_map(&game, argv);
	game.mlx = mlx_init(game.width * TILE_SIZE,
			game.height * TILE_SIZE, "FOX", true);
	if ((!game.mlx))
	{
		free_and_exit(&game);
		mlx_terminate(game.mlx);
	}
	image = mlx_new_image(game.mlx, game.width * TILE_SIZE,
			game.height * TILE_SIZE);
	add_graphics(&game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	mlx_image_to_window(game.mlx, image, 0, 0);
	mlx_loop_hook(game.mlx, &controls, &game);
	mlx_close_hook(game.mlx, close_func, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (1);
}
