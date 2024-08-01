/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:06:37 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/31 14:14:24 by jlehtone         ###   ########.fr       */
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

void	free_images(mlx_image_t ***image_ptr)
{
	int			i;
	int			count;
	mlx_image_t	**image;

	if (image_ptr == NULL || *image_ptr == NULL)
		return ;
	i = 0;
	count = 0;
	image = *image_ptr;
	while (image[count] != NULL)
		count++;
	while (i < count)
	{
		free(image[i]);
		i++;
	}
	free(image);
	*image_ptr = NULL;
}

void	free_and_exit(t_game *game, int error)
{
	free_map(game);
	if (game->player)
	{
		free_images(&game->player->animation);
		free_images(&game->player->rev_anim);
		free(game->player);
	}
	if (game->enemy)
	{
		free_images(&game->enemy->animation);
		free_images(&game->enemy->rev_anim);
		free(game->enemy);
	}
	if (game->chicken)
	{
		free_images(&game->chicken->animation);
		free(game->chicken);
	}
	if (game->mlx->window)
		mlx_close_window(game->mlx);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(error);
}

void	display_error(t_game *game, char *string)
{
	ft_printf("ERROR\n");
	ft_printf("%s\n", string);
	free_and_exit(game, 1);
}
