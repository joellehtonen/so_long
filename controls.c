/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 11:20:22 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	move_up(t_game *game)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	
	
	x = game->imgs->player->instances[0].x;
 	new_y = game->imgs->player->instances[0].y - 5;
	ghost_box = (t_box){x, new_y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + TILE_SIZE, ghost_box.y) == FALSE)
	{
		game->imgs->player->instances[0].y -= 5;
		game->move_count++;
		// update animation
		return (TRUE);
	}
	else
		return (FALSE);
}
t_bool	move_down(t_game *game)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	
	x = game->imgs->player->instances[0].x;
 	new_y = game->imgs->player->instances[0].y + 5;
	ghost_box = (t_box){x, new_y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y + TILE_SIZE) == FALSE
		&& is_wall(game, ghost_box.x + TILE_SIZE, ghost_box.y + TILE_SIZE) == FALSE)
	{
		game->imgs->player->instances[0].y += 5;
		game->move_count++;
		//update animation
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	move_left(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
 	int		y;
	
	y = game->imgs->player->instances[0].y;
 	new_x = game->imgs->player->instances[0].x - 5;
	ghost_box = (t_box){new_x, y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x, ghost_box.y + TILE_SIZE) == FALSE)
	{
		game->imgs->player->instances[0].x -= 5;
		game->move_count++;
		//update animation
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	move_right(t_game *game)
{
	t_box	ghost_box;
	int		new_x;
 	int		y;
	
	y = game->imgs->player->instances[0].y;
 	new_x = game->imgs->player->instances[0].x + 5;
	ghost_box = (t_box){new_x, y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, ghost_box.x + TILE_SIZE, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + TILE_SIZE, ghost_box.y + TILE_SIZE) == FALSE)
	{
		game->imgs->player->instances[0].x += 5;
		game->move_count++;
		//update animation
		return (TRUE);
	}
	else
		return (FALSE);
}

void controls(void *content)
{
	t_bool	movement;
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
	if (movement)
		ft_printf("MOVES: %d\n", game->move_count);
	collect_stuff(game);
}
