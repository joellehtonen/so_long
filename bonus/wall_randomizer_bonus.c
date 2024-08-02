/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_randomizer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:41:13 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/02 11:19:57 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static unsigned int	lgc_randomizer(unsigned int seed)
{
	unsigned int	a;
	unsigned int	c;
	unsigned int	m;
	unsigned int	value;

	a = 1103515245;
	c = 12345;
	m = 0x7fffffff;
	value = (a * seed + c) & m;
	return (value);
}

static unsigned int	get_random_index(unsigned int *seed)
{
	unsigned int	value;

	*seed = lgc_randomizer(*seed);
	value = (*seed % 4) + 1;
	return (value);
}

void	wall_randomizer(t_game *game, int x, int y)
{
	unsigned int	value;
	unsigned int	random_index;

	value = (x * y + x) % (x + y + 1);
	random_index = get_random_index(&value);
	mlx_image_to_window(game->mlx, game->world[random_index],
		x * TILE_SIZE + 12, y * TILE_SIZE + 12);
	mlx_set_instance_depth(&game->world[random_index]->instances[0], 1);
}
