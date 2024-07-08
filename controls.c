/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	move_up(t_game *game)
{
	if ()//no wall
	{
		game->imgs->player->instances[0].y -= 5;
		game->move_count++;
		return (TRUE);
	}
}
t_bool	move_down(t_game *game)
{
	if ()
	{
		game->imgs->player->instances[0].y += 5;
		game->move_count++;
		return (TRUE);
	}
}
t_bool	move_left(t_game *game)
{
	if ()
	{
		game->imgs->player->instances[0].x -= 5;
		game->move_count++;
		return (TRUE)
	}
}
t_bool	move_right(t_game *game)
{
	if ()
	{
		game->imgs->player->instances[0].x += 5;
		game->move_count++;
		return (TRUE);
	}
}

void ft_controls(t_game *game)
{
	t_bool movement;
	
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
}
