/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:19:11 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/15 14:42:47 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls_horizontal(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	ft_printf("inside check_walls_horizontal\n");
	while (x < game->width)
	{
		//ft_printf("entering first loop\n");
		if (game->map[0][x] != '1')
		{
		//	ft_printf("breaking out\n");
			return (0);
		}
		x++;
		//ft_printf("x is %d\n", x);
	}
	//ft_printf("first loop done\n");
	x = 0;
	y = game->height - 1;
	//ft_printf("y is %d\n", y);
	//ft_printf("x is %d\n", x);
	while (x < game->width)
	{
		//ft_printf("entering second loop\n");
		if (game->map[y][x] != '1')
		{
		//	ft_printf("breaking out\n");
			return (0);
		}
		x++;
	//	ft_printf("x is %d\n", x);
	}
	ft_printf("exiting horizontal\n");
	return (1);
}

static int	check_walls_vertical(t_game *game)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	ft_printf("inside check_walls_vertical\n");
	while (y < game->height - 1)
	{
		if (game->map[y][x] != '1')
			return (0);
		y++;
		//ft_printf("y is %d\n", y);
	}
	//ft_printf("first loop done\n");
	x = game->width - 1;
	y = 0;
	//ft_printf("y is %d\n", y);
	//ft_printf("x is %d\n", x);
	while (y < game->height - 1)
	{		
		//ft_printf("entering second loop\n");
		if (game->map[y][x] != '1')
		{
		//	ft_printf("breaking out\n");
			return (0);
		}
		y++;
	//	ft_printf("y is %d\n", y);
	}
	ft_printf("exiting vertical\n");
	return (1);
}

static int check_rectangular(t_game *game)
{
	int	len;
	int compare;
	int	y;
	
	ft_printf("inside check_rectangular\n");
	len = game->width + 1;
	y = 0;
	while (y > game->height - 1)
	{
		compare = ft_strlen(game->map[y]);
		if (compare != len)
			return (0);
		y++;
	}
	ft_printf("exiting rectangular\n");
	return (1);
}

static int	check_count(t_game *game)
{
	ft_printf("inside check_count\n");
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
	ft_printf("collectables: %d\n", game->collectables);
	ft_printf("players: %d\n", game->start);
	ft_printf("exits: %d\n", game->exit);
	if  (game->exit != 1 || game->start != 1 || game->collectables == 0)
		return (0);
	else
	{
		ft_printf("exiting count\n");
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
