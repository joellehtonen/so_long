/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:16:24 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/24 13:05:43 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void collect_stuff(t_game *game)
{
 	int		position_x;
 	int 	position_y;
	t_box	player;
	int		frame;
	
	ft_printf("MOVES: %d\n", game->move_count);
	frame = game->player->frame;
	position_x = game->player->animation[frame]->instances[0].x;
 	position_y = game->player->animation[frame]->instances[0].y;
	player = (t_box){position_x, position_y, TILE_SIZE, TILE_SIZE};
	collectable_collision(game, player, position_x, position_y);
	exit_collision(game, player, position_x, position_y);
}
