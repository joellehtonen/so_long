/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/10 10:11:45 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void initialize_variables(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->collectables = 0;
	game->exit = 0;
	game->start = 0;
	game->move_count = 0;
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
	image = mlx_new_image(game.mlx, 256, 256); //start a window?
	//game.window = mlx_new_window(game.mlx, *game->width, game->height, "FOX");
	ft_memset(image->pixels, 200, image->width * image->height * sizeof(int32_t) );
	add_graphics(&game);
	mlx_image_to_window(game.mlx, image, 0, 0);
	mlx_loop_hook((&game)->mlx, ft_controls, (&game)->mlx); //control input/output
	mlx_loop((&game)->mlx);
	mlx_terminate((&game)->mlx);
	return (1);
}

		
	// if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	// {
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (!(image = mlx_new_image(mlx, 128, 128)))
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	// if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	// {
	// 	mlx_close_window(mlx);
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }
	
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	// mlx_loop_hook(mlx, ft_hook, mlx);

	// mlx_loop(mlx);
	// mlx_terminate(mlx);



//gcc main.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm