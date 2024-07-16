/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/16 11:47:32 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_game *game)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	
	
	x = game->imgs->player->instances[0].x;
 	new_y = game->imgs->player->instances[0].y - 4;
	ghost_box = (t_box){x, new_y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y) == FALSE)
	{
		game->imgs->player->instances[0].y -= 4;
		game->move_count++;
		// update animation
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
	
	x = game->imgs->player->instances[0].x;
 	new_y = game->imgs->player->instances[0].y + 4;
	ghost_box = (t_box){x, new_y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->imgs->player->instances[0].y += 4;
		game->move_count++;
		//update animation
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
	
	y = game->imgs->player->instances[0].y;
 	new_x = game->imgs->player->instances[0].x - 4;
	ghost_box = (t_box){new_x, y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->imgs->player->instances[0].x -= 4;
		game->move_count++;
		//update animation
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
	
	y = game->imgs->player->instances[0].y;
 	new_x = game->imgs->player->instances[0].x + 4;
	ghost_box = (t_box){new_x, y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->imgs->player->instances[0].x += 4;
		game->move_count++;
		//update animation
		return (1);
	}
	else
		return (0);
}

void controls(void *content)
{
	int	movement;
	t_game	*game;

	game = (t_game *)content;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		movement = move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		movement = move_down(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement = move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement = move_right(game);
	if (movement == 1)
		ft_printf("MOVES: %d\n", game->move_count);
	collect_stuff(game);
}
