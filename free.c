/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:06:37 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 16:32:28 by jlehtone         ###   ########.fr       */
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

static void	free_images(t_game *game, mlx_image_t ***image_ptr)
{
	int			i;
	mlx_image_t	**image;

	if (image_ptr == NULL || *image_ptr == NULL)
		return ;
	i = 0;
	image = *image_ptr;
	while (image[i++] != NULL)
		mlx_delete_image(game->mlx, image[i]);
	free(image);
	*image_ptr = NULL;
}

void	free_and_exit(t_game *game)
{
	free_map(game);
	if (game->world)
		free_images(game, &game->world);
	if (game->player)
	{
		free_images(game, &game->player->animation);
		free(game->player);
	}
	if (game->chicken)
	{
		free_images(game, &game->chicken->animation);
		free(game->chicken);
	}
	if (game->mlx)
	{
		if (game->mlx->window)
			mlx_close_window(game->mlx);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	display_error(t_game *game, char *string)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", string);
	free_and_exit(game);
}
