/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:29:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 11:10:33 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_and_exit(t_game *game, int error)
{
	int	i;

	i = 0;
	mlx_terminate(game->mlx);
	//free(game->txts); is this necessary anymore?
	free(game->imgs);
	while (game->map)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
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
	mlx_loop_hook(game.mlx, &controls, &game); //control input/output
	mlx_loop(game.mlx);
	free_and_exit(&game, 0);
	return (1);
}



// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

// void ft_hook(void* param)
// {
// 	mlx_t* mlx = param;

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

// // -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	mlx_t* mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }


//gcc main.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm