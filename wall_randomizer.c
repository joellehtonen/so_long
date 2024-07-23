/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_randomizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:41:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/23 15:17:13 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int lgc_randomizer(unsigned int seed)
{
	unsigned int a;
    unsigned int c;
    unsigned int m;

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
	unsigned int value = (x * y + x) % (x + y + 1);
	unsigned int random_index;

	random_index = get_random_index(&value);
	mlx_image_to_window(game->mlx, game->world->image[random_index], x * TILE_SIZE, y * TILE_SIZE);
}