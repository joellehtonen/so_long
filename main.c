/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/15 14:44:44 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_and_exit(t_game *game, int error)
{
	int	i;

	i = 0;
	ft_printf("into free and exit\n");
	//REMEMBER TO FREE THE LINES OF GNL!!
	//free(game->txts); is this necessary anymore?
	if (game->image_content == 1)
		free(game->imgs);
	//ft_printf("after freeing imgs (if any)\n");
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	//	ft_printf("freeing map loop %d\n", i);
	}
	free(game->map);
	//ft_printf("map freed\n");
	//mlx_terminate(game->mlx); //THIS CAUSES SEGFAULT
	//ft_printf("after termination\n");
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
	game.mlx = mlx_init(256, 256, "FOX", true);
	ft_printf("init done\n");
	image = mlx_new_image(game.mlx, 512, 512); //start a window?
	ft_printf("image done\n");
	//game.window = mlx_new_window(game.mlx, *game->width, game->height, "FOX");
	ft_memset(image->pixels, 200, image->width * image->height * sizeof(int32_t));
	ft_printf("memset done\n");
	add_graphics(&game);
	ft_printf("graphics done\n");
	mlx_image_to_window(game.mlx, image, 0, 0);
	ft_printf("image to window done\n");
	mlx_loop_hook(game.mlx, &controls, &game); //control input/output
	mlx_loop(game.mlx);
	//mlx_terminate(game.mlx);
	free_and_exit(&game, 0);
	return (1);
}
