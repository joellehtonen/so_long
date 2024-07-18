/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:16:24 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/18 13:56:28 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void reach_exit(t_game *game, int position_x, int position_y)
{
	if (is_exit(game, position_x, position_y) == TRUE
		|| is_exit(game, position_x + MOVE_SIZE, position_y) == TRUE
		|| is_exit(game, position_x, position_y + MOVE_SIZE) == TRUE
		|| is_exit(game, position_x + MOVE_SIZE, position_y + MOVE_SIZE) == TRUE)
	{
		if (game->collectables == 0)
		{
			free_and_exit(game, 0);
		}
		else
			return ;
	}
}

static void delete_collected(t_game *game, int x, int y)
{
	int	i;
	
	i = 0;
	while (i < game->collectables)
	{
		if (game->imgs->collect->instances[i].y == y
			&& game->imgs->collect->instances[i].x == x
			&& game->imgs->collect->instances[i].enabled == true)
		{
			game->imgs->collect->instances[i].enabled = false;
			game->collectables--;
			ft_printf("collectables left: %d\n", game->collectables);
			if (game->collectables == 0)
			{
				game->imgs->exit_ready->instances[i].enabled == true;
			}
			return ;
		}
		i++;
	}
}

void collect_stuff(t_game *game)
{
 	int		position_x;
 	int 	position_y;

	position_x = game->imgs->player->instances[0].x;
 	position_y = game->imgs->player->instances[0].y;
	if (is_collectable(game, position_x, position_y) == TRUE)
		delete_collected(game, position_x, position_y);
	if (is_collectable(game, position_x + MOVE_SIZE, position_y) == TRUE)
		delete_collected(game, position_x + TILE_SIZE, position_y);
	if (is_collectable(game, position_x, position_y + MOVE_SIZE) == TRUE)
		delete_collected(game, position_x, position_y + TILE_SIZE);
	if (is_collectable(game, position_x + MOVE_SIZE, position_y + MOVE_SIZE) == TRUE)
		delete_collected(game, position_x + TILE_SIZE, position_y + TILE_SIZE);
	reach_exit(game, position_x, position_y);
}
