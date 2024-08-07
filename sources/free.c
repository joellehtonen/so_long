/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:06:37 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 10:06:34 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_and_exit(t_game *game, int error)
{
	free_map(game);
	if (game->text)
		mlx_delete_texture(game->text);
	if (game->world)
		free_images(game, &game->world);
	if (game->player)
	{
		if (game->player->animation)
			free_images(game, &game->player->animation);
		free(game->player);
	}
	if (game->chicken)
	{
		if (game->chicken->animation)
			free_images(game, &game->chicken->animation);
		free(game->chicken);
	}
	if (game->mlx)
	{
		if (game->mlx->window)
			mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	exit(error);
}

void	display_error(t_game *game, char *string)
{
	ft_printf("Error\n");
	ft_printf("%s\n", string);
	free_and_exit(game, 1);
}
