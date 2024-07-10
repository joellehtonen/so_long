/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:28:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/10 14:27:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool is_wall(t_game *game, int x, int y)
{
	if (game->map[x / TILE_SIZE][y / TILE_SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}

t_bool is_collectable(t_game *game, int x, int y)
{
	if (game->map[x / TILE_SIZE][y / TILE_SIZE] == 'c')
		return (TRUE);
	else
		return (FALSE);
}

t_bool is_exit(t_game *game, int x, int y)
{
	if (game->map[x / TILE_SIZE][y / TILE_SIZE] == 'e')
		return (TRUE);
	else
		return (FALSE);
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
