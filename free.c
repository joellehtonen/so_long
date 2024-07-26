/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:06:37 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/26 15:24:14 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL)
		return ;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

// void	free_images(mlx_image_t **image)
// {
// 	int	i;
// 	int count;

// 	i = 0;
// 	count = 0;
// 	if (image == NULL)
// 		return ;
// 	while (image[count] != NULL)
// 		count++;
// 	while (i < count)
// 	{
// 		free(image[i]);
// 		i++;
// 	}
// 	free(image);
// }

void	free_and_exit(t_game *game, int error)
{
	//ft_printf("FREEING AND EXITING\n");
	//REMEMBER TO FREE THE LINES OF GNL!!
	free_map(game);
	// free_images(game->world->image);
	// free_images(game->chicken->animation);
	// free_images(game->player->animation);
	// free_images(game->player->reverse_animation);
	// free_images(game->enemy->animation);
	// free_images(game->enemy->reverse_animation);
	if (game->mlx->window)
		mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	exit(0);
}

void	display_error(t_game *game, int e)
{
	if (e == 1)
		ft_printf("The map must be closed/surrounded by walls\n");
	if (e == 2)
		ft_printf("The map must be rectangular\n");
	if (e == 3)
		ft_printf("Invalid characters OR invalid amount of characters\n");
	if (e == 4)
		ft_printf("No valid path in the map\n");
	free_and_exit(game, 1);
}