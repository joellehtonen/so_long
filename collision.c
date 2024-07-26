/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:28:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/26 13:09:35 by jlehtone         ###   ########.fr       */
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

void collectable_collision(t_game *game, t_box player, int x, int y)
{
	t_box	collectable;
	int		i;
	
	i = 0;
	while (i < game->collectables)
	{
		if (game->chicken->animation[0]->instances[i].enabled)
		{
			x = game->chicken->animation[0]->instances[i].x;
			y = game->chicken->animation[0]->instances[i].y;
			collectable = (t_box){x, y, TILE_SIZE, TILE_SIZE};
			if (check_collision(player, collectable) == TRUE)
			{
				update_chicken_animation(game, i);	
				game->collected++;
				ft_printf("collected: %d\n", game->collected);
			}
		}
		i++;
	}
	if (game->collectables == game->collected)
		game->world->image[6]->instances[0].enabled = false;
	return ;
}

void exit_collision(t_game *game, t_box player, int x, int y)
{
	t_box exit;
	
	x = game->world->image[5]->instances[0].x;
	y = game->world->image[5]->instances[0].y;
	exit = (t_box){x, y, MOVE_SIZE, MOVE_SIZE};
	if (game->collected == game->collectables)
	{
		if (check_collision(player, exit) == TRUE)
		{
			ft_printf("YOU WIN! (the fox says thank you)\n");
			free_and_exit(game, 0);
		}
	}
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
