/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:23:10 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/31 09:49:19 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_enemy_animations(t_game *game, int x, int y)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->enemy->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->animation[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->animation[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->rev_anim[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->rev_anim[i]->instances[0].enabled = false;
		i++;
	}
	game->enemy->x = game->player->x;
	game->enemy->y = game->player->y;
}
