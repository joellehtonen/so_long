/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:28:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/19 12:18:15 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool is_wall(t_game *game, int x, int y)
{
	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}

// t_bool is_collectable(t_game *game, int x, int y)
// {
// 	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == 'c')
// 		return (TRUE);
// 	else
// 		return (FALSE);
// }

void is_collectable(t_game *game, int x, int y)
{
	t_box	collectable;
	t_box	player;
	int		i;
	int		position_x;
	int		position_y;

	player = (t_box){x, y, TILE_SIZE, TILE_SIZE};
	i = 0;
	while (i < game->collectables)
	{
		if (game->imgs->collect->instances[i].enabled)
		{
			position_x = game->imgs->collect->instances[i].x;
			position_y = game->imgs->collect->instances[i].y;
			ft_printf("I am enabled: %d\n", game->imgs->collect->instances[i]);
			collectable = (t_box){position_x, position_y, TILE_SIZE, TILE_SIZE};
			if (check_collision(player, collectable) == TRUE)
			{
				ft_printf("COLLISION DETECTED\n");
				game->imgs->collect->instances[i].enabled = false;
				//game->collectables--;
				game->collected++;
				ft_printf("collectables left: %d\n", game->collectables);
				return ;
			}
		}
		else if (game->imgs->collect->instances[i].enabled == 0)
			ft_printf("I am disabled: %d\n", game->imgs->collect->instances[i]);
		i++;
	}
		if ((game->collectables - game->collected) == 1)
			game->imgs->exit->instances[0].enabled = false;
		if (game->collectables == game->collected)
			game->imgs->exit_almost->instances[0].enabled = false;
	 return ;
}

void is_exit(t_game *game, int x, int y)
{
	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == 'e')
	{
		if (game->collected == game->collectables)
			free_and_exit(game, 0);
	}
	else
		return ;
}

t_bool check_collision(t_box a, t_box b)
{
	t_bool not_left;
	t_bool not_right;
	t_bool not_above;
	t_bool not_below;

	not_left = a.x < b.x + b.width;
	not_right = a.x + a.width > b.x;
	not_above = a.y < b.y + b.height;
	not_below = a.y + a.height > b.y;
	if (not_left && not_right && not_above && not_below)
		return (TRUE);
	else
		return (FALSE);
}
