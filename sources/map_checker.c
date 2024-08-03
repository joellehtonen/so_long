/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:19:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/03 10:04:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls_horizontal(t_game *game, int x, int y)
{
	while (x < game->width)
	{
		if (game->map[y][x] != '1')
			return (0);
		x++;
	}
	x = 0;
	y = game->height - 1;
	while (x < game->width)
	{
		if (game->map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_walls_vertical(t_game *game, int x, int y)
{
	while (y < game->height - 1)
	{
		if (game->map[y][x] != '1')
			return (0);
		y++;
	}
	x = game->width - 1;
	y = 0;
	while (y < game->height - 1)
	{		
		if (game->map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_rectangular(t_game *game, int y)
{
	int	len;
	int	compare;

	len = game->width + 1;
	while (y < game->height - 1)
	{
		compare = ft_strlen(game->map[y]);
		ft_printf("len is %d\n", len);
		ft_printf("compare is %d\n", compare);
		if (compare != len)
			return (0);
		y++;
	}
	len = game->width;
	compare = ft_strlen(game->map[y]);
	if (compare != len)
			return (0);
	return (1);
}

static int	check_count(t_game *game, int x, int y)
{
	int	invalid_char;

	invalid_char = 0;
	while (y < game->height - 1)
	{
		x = 0;
		while (x < game->width - 1)
		{
			if (game->map[y][x] == 'C')
				game->collectables++;
			else if (game->map[y][x] == 'P')
				game->start++;
			else if (game->map[y][x] == 'E')
				game->exit++;
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				invalid_char++;
			x++;
		}
		y++;
	}
	if (game->exit != 1 || game->start != 1 || game->collectables == 0
		|| invalid_char > 0)
		return (0);
	else
		return (1);
}

void	map_checker(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!check_walls_horizontal(game, x, y)
		|| !check_walls_vertical(game, x, y))
		display_error(game, "The map must be closed/surrounded by walls");
	if (!check_rectangular(game, y))
		display_error(game, "The map must be rectangular");
	if (!check_count(game, x, y))
		display_error(game, "Invalid characters OR invalid # of characters");
	if (!check_path(game, x, y))
		display_error(game, "No valid path in the map");
}
