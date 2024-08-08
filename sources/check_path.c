/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:11:05 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/08 12:01:18 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'p'
		|| game->map[y][x] == 'c' || game->map[y][x] == 'e'
		|| game->map[y][x] == 'o')
		return ;
	else if (game->map[y][x] == 'P')
		game->map[y][x] = 'p';
	else if (game->map[y][x] == 'C')
		game->map[y][x] = 'c';
	else if (game->map[y][x] == 'E')
		game->map[y][x] = 'e';
	else if (game->map[y][x] == '0')
		game->map[y][x] = 'o';
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
}

static int	*find_start(t_game *game, int x, int y)
{
	int	*start;

	start = malloc(sizeof(int) * 2);
	if (!start)
		display_error(game, "Malloc failed");
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				start[0] = y;
				start[1] = x;
				return (start);
			}
			x++;
		}
		y++;
	}
	return (start);
}

int	check_path(t_game *game, int x, int y)
{
	int	*start;

	start = find_start(game, x, y);
	flood_fill(game, start[0], start[1]);
	free(start);
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if (game->map[y][x] == 'P' || game->map[y][x] == 'E'
				|| game->map[y][x] == 'C')
				return (FAILURE);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
