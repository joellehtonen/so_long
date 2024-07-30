/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_randomizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:41:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 15:29:54 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int	lgc_randomizer(unsigned int seed)
{
	unsigned int	a;
    unsigned int	c;
    unsigned int	m;

	a = 1103515245;
	c = 12345;
	m = 0x7fffffff;

	return ((a * seed + c) & m);
}

static unsigned int get_random_index(unsigned int *seed)
{
	*seed = lgc_randomizer(*seed);
	return ((*seed % 4) + 1);
}

void wall_randomizer(t_game *game, int x, int y)
{
	unsigned int value;
	unsigned int random_index;

	value = (x * y + x) % (x + y + 1);
	random_index = get_random_index(&value);
	mlx_image_to_window(game->mlx, game->world[random_index], 
		x * TILE_SIZE + 8, y * TILE_SIZE);
	mlx_set_instance_depth(&game->world[random_index]->instances[0], 1);
}
