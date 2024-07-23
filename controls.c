/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/23 11:23:40 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_game *game, int frame)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	
	
	x = game->player->animation[frame]->instances[0].x;
 	new_y = game->player->animation[frame]->instances[0].y - 4;
	ghost_box = (t_box){x, new_y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y) == FALSE)
	{
		game->player->animation[frame]->instances[0].y -= 4;
		game->player->y -= 4;
		game->move_count++;
		if (game->move_count % 4 == 0)
		{
			frame++;
			if (frame > 5)
				frame = 2;
		}
		return (frame);
	}
	else
		return (0);
} 
static int	move_down(t_game *game, int frame)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	
	x = game->player->animation[frame]->instances[0].x;
 	new_y = game->player->animation[frame]->instances[0].y + 4;
	ghost_box = (t_box){x, new_y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->player->animation[frame]->instances[0].y += 4;
		game->player->y += 4;
		game->move_count++;
		if (game->move_count % 4 == 0)
		{
			frame++;
			if (frame > 5)
				frame = 2;
		}
		return (frame);
	}
	else
		return (0);
}

static int	move_left(t_game *game, int frame)
{
	t_box	ghost_box;
	int		new_x;
 	int		y;
	
	y = game->player->animation[frame]->instances[0].y;
 	new_x = game->player->animation[frame]->instances[0].x - 4;
	ghost_box = (t_box){new_x, y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->player->animation[frame]->instances[0].x -= 4;
		game->player->x -= 4;
		game->move_count++;
		if (game->move_count % 4 == 0)
		{
			frame++;
			if (frame > 5)
				frame = 2;
		}
		return (frame);
	}
	else
		return (0);
}

static int	move_right(t_game *game, int frame)
{
	t_box	ghost_box;
	int		new_x;
 	int		y;
	
	y = game->player->animation[frame]->instances[0].y;
 	new_x = game->player->animation[frame]->instances[0].x + 4;
	ghost_box = (t_box){new_x, y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->player->animation[frame]->instances[0].x += 4;
		game->player->x += 4;
		game->move_count++;
		if (game->move_count % 4 == 0)
		{
			frame++;
			if (frame > 5)
				frame = 2;
		}
		return (frame);
	}
	else
		return (0);
}

void controls(void *content)
{
	int		movement;
	t_game	*game;

	game = (t_game *)content;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		movement = move_up(game, game->frame);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		movement = move_down(game, game->frame);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement = move_left(game, game->frame);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement = move_right(game, game->frame);
	else
		movement = idle_animation(game);
	game->frame = movement;
	if (movement > 1)
	{
		ft_printf("MOVES: %d\n", game->move_count);
		collect_stuff(game);
	}
	enemy_appears(game);
}
