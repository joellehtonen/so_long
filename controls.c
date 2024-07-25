/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 11:46:16 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_up(t_game *game, int movement)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	int 	frame;
	
	frame = game->player->frame;
	x = game->player->animation[frame]->instances[0].x;
 	new_y = game->player->animation[frame]->instances[0].y - MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y) == FALSE)
	{
		game->player->animation[frame]->instances[0].y -= MOVE_SPEED;
		game->player->y -= MOVE_SPEED;
		game->move_count++;
		//movement = 0;
		if ((game->move_count % 3 == 0 || game->move_count < 4) && movement < 2)
		 	update_player_animation(game, frame);
		return (1);
	}
	else
		return (0);
}
static int	move_down(t_game *game, int movement)
{
	t_box	ghost_box;
	int		x;
 	int		new_y;
	int 	frame;
	
	frame = game->player->frame;
	x = game->player->animation[frame]->instances[0].x;
 	new_y = game->player->animation[frame]->instances[0].y + MOVE_SPEED;
	ghost_box = (t_box){x, new_y, MOVE_SIZE, MOVE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->player->animation[frame]->instances[0].y += MOVE_SPEED;
		game->player->y += MOVE_SPEED;
		game->move_count++;
		//movement = 0;
		if ((game->move_count % 3 == 0 || game->move_count < 4) && movement < 2)
		 	update_player_animation(game, frame);
		return (1);
	}
	else
		return (0);
}

static int	move_left(t_game *game, int movement)
{
	t_box	ghost_box;
	int		new_x;
 	int		y;
	int 	frame;
	
	frame = game->player->frame;
	y = game->player->animation[frame]->instances[0].y;
 	new_x = game->player->animation[frame]->instances[0].x - MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (is_wall(game, ghost_box.x, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->player->animation[frame]->instances[0].x -= MOVE_SPEED;
		game->player->x -= MOVE_SPEED;
		game->move_count++;
		//movement = 0;
		if ((game->move_count % 3 == 0 || game->move_count < 4) && movement < 2)
		 	update_player_animation(game, frame);
		return (1);
	}
	else
		return (0);
}

static int	move_right(t_game *game, int movement)
{
	t_box	ghost_box;
	int		new_x;
 	int		y;
	int 	frame;
	
	frame = game->player->frame;
	y = game->player->animation[frame]->instances[0].y;
 	new_x = game->player->animation[frame]->instances[0].x + MOVE_SPEED;
	ghost_box = (t_box){new_x, y, MOVE_SIZE, MOVE_SIZE};
	if (is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y) == FALSE
		&& is_wall(game, ghost_box.x + MOVE_SIZE, ghost_box.y + MOVE_SIZE) == FALSE)
	{
		game->player->animation[frame]->instances[0].x += MOVE_SPEED;
		game->player->x += MOVE_SPEED;
		game->move_count++;\
		//movement = 0;
		if ((game->move_count % 3 == 0 || game->move_count < 4) && movement < 2)
		 	update_player_animation(game, frame);
		return (1);
	}
	else
		return (0);
}

void controls(void *content)
{
	int		movement;
	t_game	*game;

	game = (t_game *)content;
	movement = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		movement += move_up(game, movement);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		movement += move_down(game, movement);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		movement += move_left(game, movement);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		movement += move_right(game, movement);
	//ft_printf("movement is %d\n", movement);
	//ft_printf("player's location is %d,%d\n", game->player->x, game->player->y);
	if (movement == 0)
		idle_animation(game);
	if (movement > 0)
		collect_stuff(game);
	enemy_appears(game);
}
