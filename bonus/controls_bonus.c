/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/03 10:49:53 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	move_up(t_game *game)
{
	t_box	ghost_box;
	int		x;
	int		new_y;
	int		frame;

	frame = game->player->frame;
	x = game->player->x;
	new_y = game->player->y - MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y))
	{
		game->player->animation[frame]->instances[0].y -= MOVE_SPEED;
		game->player->y -= MOVE_SPEED;
		game->move_count++;
		return (1);
	}
	else
		return (0);
}

static int	move_down(t_game *game)
{
	t_box	ghost_box;
	int		x;
	int		new_y;
	int		frame;

	frame = game->player->frame;
	x = game->player->x;
	new_y = game->player->y + MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE))
	{
		game->player->animation[frame]->instances[0].y += MOVE_SPEED;
		game->player->y += MOVE_SPEED;
		game->move_count++;
		return (1);
	}
	else
		return (0);
}

static int	move_left(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
	int		y;
	int		frame;

	game->player->left = 1;
	frame = game->player->frame;
	y = game->player->y;
	new_x = game->player->x - MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x, ghost_box.y)
		&& !is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE))
	{
		game->player->animation[frame]->instances[0].x -= MOVE_SPEED;
		game->player->x -= MOVE_SPEED;
		game->move_count++;
		return (1);
	}
	else
		return (0);
}

static int	move_right(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
	int		y;
	int		frame;

	game->player->left = 0;
	frame = game->player->frame;
	y = game->player->y;
	new_x = game->player->x + MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (!is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y)
		&& !is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE))
	{
		game->player->animation[frame]->instances[0].x += MOVE_SPEED;
		game->player->x += MOVE_SPEED;
		game->move_count++;
		return (1);
	}
	else
		return (0);
}

void	controls(void *content)
{
	int		movement;
	t_game	*game;

	game = (t_game *)content;
	movement = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		free_and_exit(game, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		movement += move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		movement += move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement += move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement += move_right(game);
	if (game->move_count % 3 == 0)
		player_run_animation(game, game->player->frame);
	if (movement == 0)
		player_idle_animation(game);
	if (movement > 0)
		collect_stuff(game);
	chicken_idle_animation(game);
	enemy_appears(game);
}
