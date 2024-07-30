/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:16:24 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 15:50:52 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void collect_stuff(t_game *game)
{
	t_box	player;
	int		frame;

	ft_printf("MOVES: %d\n", game->move_count);
	frame = game->player->frame;
	player = (t_box){game->player->x, game->player->y, TILE_SIZE, TILE_SIZE};
	collectable_collision(game, player, game->player->x, game->player->y);
	exit_collision(game, player, game->player->x, game->player->y);
}
