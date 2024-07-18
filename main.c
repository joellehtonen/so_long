/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/18 14:12:02 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_and_exit(t_game *game, int error)
{
	int	i;

	i = 0;
	ft_printf("FREEING AND EXITING\n");
	//REMEMBER TO FREE THE LINES OF GNL!!
	if (game->image_content == 1)
		free(game->imgs);
	// while (game->map[i])
	// {
	// 	free(game->map[i]);
	// 	i++;
	// }
	free(game->map);
	//mlx_terminate(game->mlx); //THIS CAUSES SEGFAULT
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 1);//define error messages later
		exit(1);
	}
	exit(0);
}

void initialize_variables(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->collectables = 0;
	game->exit = 0;
	game->start = 0;
	game->move_count = 0;
	game->map = NULL;
	game->texture_content = 0;
	game->image_content = 0;
}

int main(int argc, char **argv)
{
	t_game 		game;
	mlx_image_t *image;

	if (argc != 2)
		return (0);
	initialize_variables(&game);
	map_reader(&game, argv);
	map_checker(&game);
	game.mlx = mlx_init(game.width * TILE_SIZE, game.height * TILE_SIZE, "FOX", true);
	// if ((!game.mlx))
	// 	free_and_exit(&game, 1);
	image = mlx_new_image(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE); //start a window?
	add_graphics(&game);
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
