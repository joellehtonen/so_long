/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:06:37 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 09:45:02 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

static void	free_player_assets(t_game *game)
{
	if (game->player)
	{
		if (game->player->anim)
			free_images(game, &game->player->anim);
		if (game->player->rev_anim)
			free_images(game, &game->player->rev_anim);
		free(game->player);
	}
}

static void	free_enemy_assets(t_game *game)
{
	if (game->enemy)
	{
		if (game->enemy->anim)
			free_images(game, &game->enemy->anim);
		if (game->enemy->rev_anim)
			free_images(game, &game->enemy->rev_anim);
		free(game->enemy);
	}
}

void	free_and_exit(t_game *game, int error)
{
	free_map(game);
	if (game->txt)
		mlx_delete_texture(game->txt);
	if (game->world)
		free_images(game, &game->world);
	if (game->chicken)
	{
		if (game->chicken->anim)
			free_images(game, &game->chicken->anim);
		free(game->chicken);
	}
	free_player_assets(game);
	free_enemy_assets(game);
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
