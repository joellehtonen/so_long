/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 10:57:13 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_chicken_animations(t_game *game, int x, int y, int number)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (game->chicken->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->chicken->animation[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->chicken->animation[i]->instances[number].enabled = false;
		i++;
	}
	game->chicken->animation[0]->instances[number].enabled = true;
}

void	upload_player_animations(t_game *game, int x, int y)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (game->player->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->player->animation[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->player->animation[i]->instances[0].enabled = false;
		i++;
	}
	game->player->animation[0]->instances[0].enabled = true;
	i = 0;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->player->rev_anim[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->player->rev_anim[i]->instances[0].enabled = false;
		i++;
	}
	game->player->x = x * TILE_SIZE;
	game->player->y = y * TILE_SIZE;
}
