/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:19:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/05 15:05:13 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls_horizontal(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	while (x <= game->width)
	{
		if (game->map[x][y] != '1')
			return (0);
		x++;
	}
	x = 0;
	y = game->height;
	while (x <= game->width)
	{
		if (game->map[x][y] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_walls_vertical(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	while (y <= game->height)
	{
		if (game->map[x][y] != '1')
			return (0);
		y++;
	}
	x = game->width;
	y = 0;
	while (y <= game->height)
	{
		if (game->map[x][y] != '1')
			return (0);
		x++;
	}
	return (1);
}

int check_rectangular(t_game *game)
{
	int	x;
	int	y;

	x = game->width;
	y = 0;
	while (y <= game->height)
	{
		if (game->map[x + 1][y] != '\0')
			return (0);
		y++;
	}
	while (x >= 0)
	{
		if (game->map[x][y + 1] != '\0')
			return (0);
		x--;//will this cause issues at the edge of the map?
	}
	return (1);
}

int	check_count(t_game *game)
{
	if  (game->exit != 1
		|| game->start != 1
		|| game->collectables == 0)
	{
		return (0);
	}
	else
		return (1);
}

void map_checker(t_game *game)
{
	if (!check_walls_horizontal(game)
		|| !check_wall_vertical(game)
		|| !check_rectangular(game)
		|| !check_count(game)
		|| !check_path(game))
	{
		free_and_exit();//do this later
	}
}
