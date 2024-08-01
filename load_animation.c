/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 12:58:17 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_player_animations(t_game *game, int x, int y)
{

	mlx_image_to_window(game->mlx, game->player->animation[0],
			x * TILE_SIZE, y * TILE_SIZE);
	game->player->animation[0]->instances[0].enabled = true;
	game->player->x = x * TILE_SIZE;
	game->player->y = y * TILE_SIZE;
}
