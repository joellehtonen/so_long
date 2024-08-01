/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:28:31 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 13:35:49 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (1);
	else
		return (0);
}

void	collectable_collision(t_game *game, t_box player, int x, int y)
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
			if (check_collision(player, collectable))
			{
				game->chicken->animation[0]->instances[i].enabled = false;
				game->collected++;
				ft_printf("Chickens left to eat: %d\n",
					game->collectables - game->collected);
			}
		}
		i++;
	}
	if (game->collectables == game->collected)
		game->world[6]->instances[0].enabled = false;
	return ;
}

void	exit_collision(t_game *game, t_box player, int x, int y)
{
	t_box	exit;

	x = game->world[5]->instances[0].x;
	y = game->world[5]->instances[0].y;
	exit = (t_box){x, y, MOVE_SIZE, MOVE_SIZE};
	if (check_collision(player, exit))
	{
		if (game->collected == game->collectables)
		{
			ft_printf("YOU WIN! (the fox says thank you)\n");
			free_and_exit(game);
		}
	}
}

int	check_collision(t_box a, t_box b)
{
	int	not_left;
	int	not_right;
	int	not_above;
	int	not_below;

	not_left = a.x < b.x + b.width;
	not_right = a.x + a.width > b.x;
	not_above = a.y < b.y + b.height;
	not_below = a.y + a.height > b.y;
	if (not_left && not_right && not_above && not_below)
		return (1);
	else
		return (0);
}

void	collect_stuff(t_game *game)
{
	t_box	player;

	if (game->move_count == INT_MAX - 1)
		game->move_count = 1;
	ft_printf("MOVES: %d\n", game->move_count);
	player = (t_box){game->player->x, game->player->y, TILE_SIZE, TILE_SIZE};
	collectable_collision(game, player, game->player->x, game->player->y);
	exit_collision(game, player, game->player->x, game->player->y);
}
