/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:19:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/19 11:41:50 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls_horizontal(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
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
	ft_printf("horizontal walls\n");
	return (1);
}

static int	check_walls_vertical(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
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
	ft_printf("vertical walls\n");
	return (1);
}

static int check_rectangular(t_game *game)
{
	int	len;
	int compare;
	int	y;
	
	len = game->width + 1;
	y = 0;
	while (y > game->height - 1)
	{
		compare = ft_strlen(game->map[y]);
		if (compare != len)
			return (0);
		y++;
	}
	ft_printf("rectangle squared\n");
	return (1);
}

static int	check_count(t_game *game)
{
	int x;
	int y;
	x = 0;
	y = 0;
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
			x++;
		}
		y++;
	}
	if  (game->exit != 1 || game->start != 1 || game->collectables == 0)
		return (0);
	else
	{
		ft_printf("counts counted\n");
		return (1);
	}
}

void map_checker(t_game *game)
{
	if (!check_walls_horizontal(game)
		|| !check_walls_vertical(game)
		|| !check_rectangular(game)
		|| !check_count(game)
		|| !check_path(game))
	{
		free_and_exit(game, 1);
	}
}
